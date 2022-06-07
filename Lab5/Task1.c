#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10
#define BUFLEN 6
#define NUMTHREAD 2 /* number of threads */
void * consumer(int *id);
void * producer(int *id);
char buffer[BUFLEN];
char source[BUFLEN];

int pCount = 0;
int cCount = 0;
int buflen;
//initializing pthread mutex and condition variables
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty = PTHREAD_COND_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD] = {0,1};
int i = 0;
int j = 0;

int main()
{
    int i;
    /* define the type to be pthread */
    pthread_t thread[NUMTHREAD];
    strcpy(source,"abcdef");
    buflen = strlen(source);
    /* create 2 threads*/
    /* create one consumer and one producer */
    /* define the properties of multi threads for both threads */
    //Write Code Here
    
    pthread_t thread1, thread2;
    
    pthread_create( &thread1, NULL, (void *(*)(void *))producer, NULL);
    pthread_create( &thread2, NULL, (void *(*)(void *))consumer, NULL);
    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);
    
    exit(0);
}

void * producer(int *id)
{
    /*
     1. Producer stores the values in the buffer (Here copies values from source[] to buffer[]).
     2. Use mutex and thread communication (wait(), sleep() etc.) for critical section.
     3. Print which producer is storing which values using which thread inside the critical
     section.
     4. Producer can produce upto MAX
     */
    //Write code here
    for(int i = 0; i<5; i++){
        
        pthread_mutex_lock( &count_mutex );
        while( pCount >= BUFLEN && pCount <= NUMTHREAD )
        {
            pthread_cond_wait( &full, &count_mutex );
        }
        pthread_mutex_unlock( &count_mutex );
        
        pthread_mutex_lock( &count_mutex );
        pCount++;
        printf("%d produced by Thread %d\n", pCount, thread_id[i]);
        pthread_mutex_unlock( &count_mutex );
        
        if(pCount >= MAX) return(NULL);
        
    }
}

void * consumer(int *id)

{
    /*
     1. Consumer takes out the value from the buffer and makes it empty.
     2. Use mutex and thread communication (wait(), sleep() etc.) for critical section
     3. Print which consumer is taking which values using which thread inside the critical
     section.
     4. Consumer can consume upto MAX
     */
    //Write code here
    for(int i = 0; i<5; i++)
    {
        pthread_mutex_lock( &count_mutex );
        if( cCount < BUFLEN || cCount > NUMTHREAD )
        {
            pthread_cond_signal( &full );
        }
        pthread_mutex_unlock( &count_mutex );
        
        pthread_mutex_lock( &count_mutex );
        cCount++;
        printf("%d produced by Thread %d\n", cCount, thread_id[i]);
        pthread_mutex_unlock( &count_mutex );
        
        if(cCount >= MAX) return(NULL);
        
    }
    
}



