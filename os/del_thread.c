#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void* t_start(void* input)
{
  printf("my tid=%x From main got input %s\n", (unsigned int)pthread_self(), (char*) input);

  int cnt = 0;
  while (1)
  {
    printf("my tid=%x %s sleep\n", (unsigned int)pthread_self(), (char*) input);
    sleep(1);
    printf("my tid=%x %s after sleep\n", (unsigned int)pthread_self(), (char*) input);
    cnt++;

    if(strcmp(input, "T3") == 0)
      cnt = *(int*)0;

    if(cnt == 100)
      break;
  }
}

int main()
{
  pthread_t t1;
  pthread_t t2;
  pthread_t t3;
  pthread_t t4;
  pthread_t t5;
  pthread_t t6;
  pthread_t t7;

  pthread_create(&t1, NULL, t_start, "T1");
  pthread_create(&t2, NULL, t_start, "T2");
  pthread_create(&t3, NULL, t_start, "T3");
  pthread_create(&t4, NULL, t_start, "T4");
  pthread_create(&t5, NULL, t_start, "T5");
  pthread_create(&t6, NULL, t_start, "T6");
  pthread_create(&t7, NULL, t_start, "T7");

  printf("my tid=%x, main\n", (unsigned int)pthread_self());

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  pthread_join(t4, NULL);
  pthread_join(t5, NULL);
  pthread_join(t6, NULL);
  pthread_join(t7, NULL);
  
  return 0;
}
