Develop your own version of the cat utility in C.
If the program is run without parameters, it should just copy all
data from stdin to stdout without changes. If one or more arguments are given, 
all of them are treated as file paths from which data should be read and output
sequentially to stdout. If a non-existent file is specified or an error occurs
while reading the file, print an error message to stderr (in any form) and 
continue processing the next arguments. 

If all was successful, the output code should be zero, otherwise it shouldbe one. 

There is no need to implement options to output help (-h, --help).

Any binary data can be used as input.
- ### Note
```
Do not use standard C programming language tools
(such as fread() or fwrite()) for input/output.
The POSIX functions read() and write() should be used. 
This is a learning task. 
The goal is to learn how to use these system calls.
```

- ### Example:
```
$ ./cat << "I like cats"
I like cats
$ echo "meow" > f1.txt
$ echo "purr" > f3.txt
$ ./cat f{1..3}.txt
meow
cat: f2.txt: No such file or directory
purr
```
