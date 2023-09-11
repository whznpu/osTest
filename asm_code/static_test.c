#include<stdio.h>
#include <string.h>
// Exploring the essence of 'static' and 'inline' in assembly language.
// 我记得这里应该涉及了一些csapp最开始的内容，可以晚上去看一眼 什么数据段 代码段什么的
//https://ivanzz1001.github.io/records/post/linux/2018/04/09/linux-objdump

void my_function(){
    int x=0;
    static int y=0;
	

    printf("x: %d,y: %d\n",x,y);

	
    x+=5;
    y+=5;
}


int main(){
    my_function();
    my_function();
    my_function();


    return 0;


}

