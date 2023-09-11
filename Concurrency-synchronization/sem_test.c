#include<pthread.h>>
#include<semaphore.h>
#include<stdio.h>

int x=1;
sem_t a,b,c;
void init(int a_,int b_,int c_){
    sem_init(&a,0,a_);
    sem_init(&b,0,b_);
    sem_init(&c,0,c_);
}

void thread1(void){
    while(x!=12){
        sem_wait(&a);
        sem_wait(&c);
        x=x*2;
        sem_post(&c);
        printf("x=%d\n",x);
    }
    exit(0);
}

void thread2(void){

    while(x!=12){
        sem_wait(&b);
        sem_wait(&c);
        x=x*3;
        sem_post(&c);
        printf("x=%d\n",x);
    }
    exit(0);
}

void destory(){
    sem_destroy(&a);
    sem_destroy(&b);
    sem_destroy(&c);
}

int main(){
    init(2,1,1);

    pthread_t tid1,tid2;

    pthread_create(&tid1,NULL,thread1,NULL);
    pthread_create(&tid2,NULL,thread2,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    printf("x=%d\n",x);
    // 
}