#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void threadOn(void *msg);
void threadOff(void *msg);

int cond = 0;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

int main()
{
  printf("One thread light on, other make it off\n");

  //create two threads...
  pthread_t tidOn, tidOff;

  pthread_create(&tidOn, NULL, threadOn, "Thread On");

  printf("pthread_self = %ld\n", pthread_self());
  printf("Thread ids tidOn=%ld, tidOff=%ld\n", tidOn, tidOff);

  pthread_join(tidOn, NULL);
  
  return 0;
}

void threadOn(void *msg)
{
  while(1)
  {
    pthread_mutex_lock(&mut);
    printf("Got the mutex %s\n", __func__);
    pthread_mutex_lock(&mut);
    printf("Trying locking mutex again%s\n", __func__);

   // if(cond)
    if(0 == (cond % 2)) // Even numbers
    {
      printf("%s:", (char*)msg);
      //printf("Thread id=%ld, made to switch on the light...\n", pthread_self());
      printf("Thread id=%ld, print even=%d\n", pthread_self(), cond);
      cond++;
    }
   // cond = 0;
    pthread_mutex_unlock(&mut);
  }
}
