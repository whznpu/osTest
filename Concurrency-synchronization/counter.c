#include<pthread.h>
#include<stdio.h>

pthread_mutex_t global_lock;
unsigned long a=0;
void *routine(void *arg){
    for(int i=0;i<100000000;i++){
        // pthread_mutex_lock(&global_lock);
        while(pthread_mutex_trylock(&global_lock));
        a++;
        // while(pthread_mutex_)
        pthread_mutex_unlock(&global_lock);
    }
    return NULL;
}

int main(void){
    pthread_t threads[2];
    pthread_mutex_init(&global_lock,NULL);
    for(int i=0;i<2;i++)
        pthread_create(&threads[i],NULL,routine,0);
    for(int i=-0;i<2;i++){
        pthread_join(threads[i],NULL);
    }
    printf("%lu\n",a);
    return 0;
}