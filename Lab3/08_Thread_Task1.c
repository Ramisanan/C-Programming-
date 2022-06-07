#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void * workerFunc(void * tid)
{
    int * ttID = (int *) tid;
    printf("thread-%d  RUNNING\n",*ttID);
    printf("thread-%d  CLOSED\n",*ttID);
    pthread_exit(NULL);
}

int main()
{
    
    pthread_t tid0;
    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    pthread_t tid4;
    pthread_t * pthreads[] = {&tid0,&tid1,&tid2,&tid3,&tid4};
    
    
    for (int i = 0; i < 5; i++)
    {
        pthread_create(pthreads[i],NULL,workerFunc, (void *) pthreads[i]);
    }
    pthread_exit(NULL);
    return 0;
}

