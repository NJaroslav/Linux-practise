#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void* printA10k()
{
    int c = 10000;
    while(c != 0)
    {
        printf("a");
        c--;
    }
    return NULL;
}

void* printB10k()
{
    int c = 10000;
    while(c != 0)
    {
        printf("b");
        c--;
    } 
    return NULL;
}

void* printC10k()
{
    int c = 10000;
    while(c != 0)
    {
        printf("c");
        c--;
    }
    return NULL;
}

int main(int argc, char** argv)
{
    int res = 0;
    pthread_t tA, tB, tC;
    
    res = pthread_create(&tA, NULL, printA10k, NULL);
    if(res != 0)
    {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }
    
    res = pthread_create(&tB, NULL, printB10k, NULL);
    if(res != 0)
    {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&tC, NULL, printC10k, NULL);
    if(res != 0)
    {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }
    
    pthread_join(tA, NULL);
    pthread_join(tB, NULL);
    pthread_join(tC, NULL);
}   

     
     

    
    
        
