#include <stdio.h>
#include <pthread.h>

pthread_t tid[2];
pthread_mutex_t mut;
pthread_cond_t condVar;
char lightSwitch = 0;

void* lightOff(void *arg)
{
  // If light is on, i.e. set to 1, off it and make the lightSwitch 0.
 while(1)
  while(lightSwitch)
  {
    pthread_mutex_lock(&mut);
    printf("Lights off by tid %p %s\n", (void*)pthread_self(), (char*)arg);
    lightSwitch = 0;
   // pthread_cond_signal(&condVar);
    pthread_mutex_unlock(&mut);
    sleep(1);
  }
}

void* lightOn(void *arg)
{
  // If light is off, i.e. set to 0, on it and make the lightSwitch 1.
 while(1)
  while(!lightSwitch)
  {
    pthread_mutex_lock(&mut);
    printf("Lights on by tid %p %s\n", (void*)pthread_self(), (char*)arg);
    lightSwitch = 1;
   // pthread_cond_wait(&condVar, &mut);
    pthread_mutex_unlock(&mut);
    sleep(1);
  }
}

int main()
{
  pthread_mutex_init(&mut, NULL);
  pthread_cond_init(&condVar, NULL);

  pthread_create(&tid[0], NULL, &lightOff, "LightOff");
  pthread_create(&tid[1], NULL, &lightOn, "LightOn");

  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
  return 0;
}
