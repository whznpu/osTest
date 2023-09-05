#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <sstream>
using namespace std;

// https://blog.csdn.net/feikudai8460/article/details/107035480
//   https://zhuanlan.zhihu.com/p/400817892
//  https://en.cppreference.com/w/cpp/atomic/atomic_compare_exchange
// https://en.cppreference.com/w/cpp/atomic/atomic/fetch_add#:~:text=std%3A%3Aatomic%3CT%3E%3A%3A%20fetch_add%20C%2B%2B%20Concurrency%20support%20library%20std%3A%3Aatomic%20Atomically,is%20affected%20according%20to%20the%20value%20of%20order.
// 涉及原子操作
// CAS操作
// fecth add 操作
// 还是很好奇锁到底是怎么一回事儿 可以看一下银杏书和ostep




template <typename T>
class lock_free_stack
{
private:
    struct node
    {
        T data;
        node *next;

        node(T const &data_):
        data(data_),next(nullptr) {}
    };

    std::atomic<node *> head;
    std::atomic<size_t> stack_size;// 原子计数器

public:

    lock_free_stack() :head(nullptr),stack_size(0) {} // 初始化计数器


    void push(T const &data,int thread_id)
    {
        node *const new_node = new node(data);
        new_node->next = head.load(); // head更新，这语句需要重来一遍
        while (!head.compare_exchange_strong(new_node->next, new_node))
            ;
        stack_size.fetch_add(1);// 增加计数器
        std::ostringstream oss;
        oss << "Thread " << thread_id << " pushed " << data << std::endl;
        std::cout << oss.str();
    }
    bool pop(T &data,int thread_id)
    {
        node *old_head = head.load();

        while (old_head && !head.compare_exchange_strong(old_head, old_head->next));
        if (old_head)
        {
            data = old_head->data;
            delete old_head;
            stack_size.fetch_sub(1);
            std::ostringstream oss;
            oss << "Thread " << thread_id << " popped " << data << std::endl;
            std::cout << oss.str();
            return true;
        }
        // 栈为空
        return false;
    }

    node* top(){
        return head.load();
    }

    size_t size() const
    {   return stack_size.load();
    }

    // 检查栈为空
    bool empty() const
    {
        return head.load() == nullptr;
    }
};

const int num_threads = 4;
const int num_pushes = 10000;

lock_free_stack<int> my_stack;

void push_data(int thread_id) {
    for (int i = 0; i < num_pushes; ++i) {
        my_stack.push(i, thread_id);
    }
}

void pop_data(int thread_id) {
    for (int i = 0; i < num_pushes; ++i) {
        int data;
        if (my_stack.pop(data, thread_id)) {
            // 在这里可以对弹出的数据进行处理
        }
    }
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(push_data, i); // 传递线程编号
    }

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(pop_data, i); // 传递线程编号
    }

    for (std::thread &t : threads) {
        t.join();
    }

    std::cout << "Remaining items in the stack: " << my_stack.size() << std::endl;

    return 0;
}