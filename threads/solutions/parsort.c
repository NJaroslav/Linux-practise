#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>

//gcc parsort.c -pthread

//LENGTH of array must be greater then number of threads
#define LENGTH 12
#define NUM_THREADS 4


const int NUMBERS_PER_THREAD = LENGTH / NUM_THREADS;
const int OFFSET = LENGTH % NUM_THREADS;


int arr[LENGTH] = {127, 6543, 129, 7, 3, 2, 11, 17, 11, 13, 1663, 109};


void *thread_qsort(void* arg);
int cmp (const void * a, const void * b);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);


int main(void) {
    pthread_t threads[NUM_THREADS];
    int result_code;
    int i;

    for(i = 0; i < NUM_THREADS; ++i) {
        result_code = pthread_create(&threads[i], NULL, thread_qsort, (void *)i);
        assert(!result_code);
    }

    for(i = 0; i < NUM_THREADS; ++i) {
        result_code = pthread_join(threads[i], NULL);
        assert(!result_code);
    }

    mergeSort(arr, 0, LENGTH - 1);

    for(i = 0; i < LENGTH; ++i) {
        printf("%d ", arr[i]);
    }

    exit(EXIT_SUCCESS);
}


void *thread_qsort(void* arg) {
    long i = (long)arg;
    int left = i * NUMBERS_PER_THREAD;
    int right = (i + 1) * (NUMBERS_PER_THREAD) - 1;  
    if(right == NUM_THREADS - 1) {
        right += OFFSET;
    }  
    qsort(arr + left, right - left + 1, sizeof(int), cmp);
    return NULL;
}


int cmp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
  
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}
