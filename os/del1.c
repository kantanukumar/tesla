#include <stdio.h>
#include <pthread.h>

void* start_thread(void* in)
{
    printf("in=%s\n", (char*)in);
}

// #error "LLL"

int main()
{
    pthread_t t1;

    pthread_create(&t1, NULL, start_thread, "T1");
    pthread_join(t1, NULL);

}