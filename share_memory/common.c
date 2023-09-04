#include "common.h"
static int commShm(int size, int flags) // 创建共享内存
{
    key_t key = ftok(PATHNAME, PROJ_ID);
    if (key < 0)
    {
        perror("ftok");
        return -1;
    }
    int shmid = shmget(key, size, flags);
    if (shmid < 0)
    {
        perror("shmget");
        return -2;
    }
    return shmid;
}
int createShm(int size)
{
    return commShm(size, IPC_CREAT | IPC_EXCL);
}
int getShm(int size) // 获取共享内存
{
    return commShm(size, IPC_CREAT);
}
int destoryShm(int shmid) // 销毁共享内存
{
    if (shmctl(shmid, IPC_RMID, NULL) < 0)
    {
        perror("shmctl");
        return -3;
    }
}
