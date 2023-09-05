#include "common.h"
int main()
{
    int shmid = getShm(0);                      // 创建共享内存
    char *addr = (char *)shmat(shmid, NULL, 0); // 将共享内存进行挂接

    if(addr == (char *)(-1)){
        perror("shmat");
        return -1;
    }
    int i = 0;
    while (i < 200)
    {
        addr[i] = 'A';
        i++;
        addr[i] = 0;
        sleep(1);
    }
    shmdt(addr); // 取消共享内存
    return 0;
}
