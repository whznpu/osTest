#include "common.h"
int main()
{
    int shmid = createShm(4096);                // 创建共享内存
    char *addr = (char *)shmat(shmid, NULL, 0); // 将共享内存进行挂接
    int i = 0;
    while (i++ < 26)
    {
        printf("client：%s\n", addr);
        sleep(1);
    }
    shmdt(addr); // 取挂接
    sleep(1);
    destoryShm(shmid);
    return 0;
}
