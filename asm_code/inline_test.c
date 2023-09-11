#include<stdio.h>
// int add_inline(int a,int b);
// inline int add_inline(int a,int b){
    // return a+b;
// }
// static inline int __attribute__((always_inline)) add_inline(int a,int b){
//     return a+b;
// }
inline int __attribute__((always_inline)) add_inline(int a,int b){
    return a+b;
}


int add(int a,int b){
    return a+b;
}

int main(){
    int a=add(1,2);

    int b=add_inline(2,3);
}
