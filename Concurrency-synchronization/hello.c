/*************************************************************************
    > File Name       : hello.c
    > Author          : enjoy5512
    > Mail            : enjoy5512@163.com 
    > Created Time    : 2023年09月05日 星期二 09时34分43秒
 ************************************************************************/

#include<stdio.h>
#include "thread.h"

// int x=0;

void Thello(int id){
     int x=0;
	x++;
	printf("%d\n",x);
}

int main(int argc,char *argv[])
{
	for(int i=0;i<10;i++){
		spawn(Thello);
	}
     return 0;
}
