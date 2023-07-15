#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* threadOn(void *msg);
void* threadOff(void *msg);

int cond = 0;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mut2 = PTHREAD_MUTEX_INITIALIZER;

int main()
{
  printf("One thread light on, other make it off\n");

  //create two threads...
  pthread_t tidOn, tidOff;

  pthread_create(&tidOn, NULL, threadOn, "Thread On");
  pthread_create(&tidOff, NULL, threadOff, "Thread Off");

  printf("pthread_self = %ld\n", pthread_self());
  printf("Thread ids tidOn=%ld, tidOff=%ld\n", tidOn, tidOff);

  pthread_join(tidOn, NULL);
  pthread_join(tidOff, NULL);
  
  return 0;
}

void* threadOn(void *msg)
{
  while(1)
  {
    pthread_mutex_lock(&mut);
  //  pthread_mutex_lock(&mut2);
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

void* threadOff(void *msg)
{
  while(1)
  {
 //   pthread_mutex_lock(&mut2);
    pthread_mutex_lock(&mut);
    //if(!cond)
    if(cond % 2)
    {
      printf("%s:", (char*)msg);
      //printf("Thread id=%ld, made to switch off the light...\n", pthread_self());
      printf("Thread id=%ld, print odds=%d\n", pthread_self(), cond);
      cond++;
    }
    // cond = 1;
    pthread_mutex_unlock(&mut);
  }
}


