- Write a program that performs parallel sorting of an array in memory: 
the array is divided into n equal parts, each of them is processed by a separate thread, 
and then the sorting is performed by merging. Use standard library sorting algorithm to sort each of the parts.
### Run:
```
gcc parsort.c -pthread -o parsort
./parsort
```
