In addition to the cat utility, there is a reverse version in the coreutils set:
the tac utility. It outputs the lines in reverse order (from last to first).

Write a simple reverse version of the cp utility which should be able to 
copy a file and reverse the byte order of the file.
For input/output use file mapping method (memory mapping).

- ### Input
Your program will run with two command line arguments:
a source path and a destination path. 
It is guaranteed that the source file exists and is readable. 
If the target file exists, its contents must be replaced. 

- ### Example:
```
$ printf abcde > src.txt
$ ./pc src.txt dst.txt
$ cat dst.txt
edcba
```
- ### Run:
```
$ printf something > src.txt
$ gcc pc.c -o pc
$ ./pc src.txt dst.txt
