#ifndef __COMM_H__
#define __COMM_H__
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define PATHNAME "."
#define PROJ_ID 0x6666
int createShm(int size);   // 创建共享内存
int getShm(int size);      // 获取共享内存
int destoryShm(int shmid); // 销毁共享内存
#endif