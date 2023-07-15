#include <stdio.h>
#include <pthread.h>

int volatile gVar = 0;
pthread_mutex_t mutex;
pthread_cond_t cv;

void printFunc(void *in)
{
  while(gVar <= 20)
  {
    printf("TID %p printing %s gVar=%d\n", (void*)pthread_self(), (char*)in, gVar);
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cv, &mutex);
    ++gVar;
    sleep(1);
    pthread_cond_signal(&cv);
    pthread_mutex_unlock(&mutex);

  }
}

int main()
{
  pthread_t tid1, tid2;


  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&cv, NULL);

  pthread_create(&tid1, NULL, printFunc, "T1");
  pthread_create(&tid2, NULL, printFunc, "T2");

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
//  pthread_exit(0);
//  pthread_exit(0);

  return 0;
}
