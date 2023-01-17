#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

pthread_mutex_t mutex;
pthread_cond_t cond;

struct TContext {
    const char* Name;
    int* Counter;
    int Mod;
};

void* ThreadFunc(void* arg) {
    struct TContext* ctxt = arg;
    int* counter = ctxt->Counter;
    fprintf(stderr, "This is %s thread\n", ctxt->Name);
    while (*counter < MAX) {
        if (*counter % 2 == 0) {
            printf("%d ", (*counter)++);
            pthread_cond_signal(&cond);
        }
        else {
            printf("%d ", (*counter)++);
            pthread_cond_wait(&cond,&mutex);
        }
   
    }
    pthread_exit(0);
}

int main()
{
    pthread_t t1;
    pthread_t t2;

    int counter = 0;
    struct TContext ctxt1 = {"even", &counter, 0};
    struct TContext ctxt2 = {"odd", &counter, 1};
    pthread_create(&t1, 0, ThreadFunc, &ctxt1);
    pthread_create(&t2, 0, ThreadFunc, &ctxt2);

    pthread_join(t1, 0);
    pthread_join(t2, 0);
    printf("\n");
    return 0;
}
