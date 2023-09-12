#include<stdio.h>

int add(int x,int y){
    int a=x+y;
    // asm("");
    __asm__("movl %edx, -0x4(%rbp)");
    return a;
}

void change(){
    int a=10,b;
    __asm__("movl %1, %%eax\n\t"
            "movl %%eax, %0"
            :"=r"(b)  
            :"r"(a)
            :"%eax");
}
static unsigned int log12(unsigned int word){
    asm volatile("bsfl %1, %0": "=r"(word):"r"(word));
    return word;
}

void square(int x){
    int x_=0;
    __asm__("leal (%1,%1,1),%0"
            : "=r" (x_)
            : "r" (x)
            );
    printf("x_=%d\n",x_);
}

int main(){

    printf("result=%d\n",add(1,2));
    unsigned int x=2;
    printf("loc=%d\n",log12(x));
    square(2);
    return 0;

}