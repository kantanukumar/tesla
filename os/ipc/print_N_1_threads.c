/*
    This program prints numbers from N to 1, each in separate thread.
*/

#include <stdio.h>
#include <pthread.h>
#include "stdlib.h"
#include "unistd.h"

#define Thread_Size 10

pthread_t thread_id[Thread_Size];
int number = 10;

void* number_printer(void* arg);
int main()
{
    for(int i=0; i<Thread_Size;i++)
    {
        int rc=pthread_create(&thread_id[i],NULL,
                       number_printer,NULL);
        if(rc !=0){
            perror("Thread error");
        }
        // sleep(1);
    }

    for(int i=0;i<Thread_Size;i++)
    {
        pthread_join(thread_id[0],NULL);
    }

    return 0;
}

void* number_printer(void *arg){

    printf("%d\n",number);
    number--;

}

#if 0
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t lock;
int gNum;

void * printNum(void *i)
{
    pthread_mutex_lock(&lock);

    printf("Thread ID %p printing %d, i=%d\n", (void*) pthread_self(), gNum, (*(int*)(i)));
    --gNum;

    pthread_mutex_unlock(&lock);
}

int main()
{
    printf("Enter max numbers to print: ");
    scanf("%d", &gNum);

    pthread_t *arr_tid = NULL;
    pthread_mutex_init(&lock, NULL);

    arr_tid = (pthread_t*) malloc(sizeof(pthread_t) * gNum);
    memset(arr_tid, 0, sizeof(pthread_t) * gNum);

    pthread_attr_t *arr_attr = NULL;
    arr_attr = (pthread_attr_t*) malloc(sizeof(pthread_attr_t) * gNum);
    memset(arr_attr, 0, sizeof(pthread_attr_t) * gNum);

    int i = gNum;

    while(i--)
    {
        pthread_attr_init(&arr_attr[i]);
        pthread_attr_setdetachstate(&arr_attr[i], PTHREAD_CREATE_DETACHED);
        pthread_create(&arr_tid[i], &arr_attr[i], printNum, &i);
        pthread_detach(arr_tid[i]);
    }

    return 0;
}
#endif
