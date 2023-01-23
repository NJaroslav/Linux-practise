#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFSIZE 4096


static int
cat_read_write(int fd){
    char buf[BUFFSIZE];
    ssize_t n;
    while((n = read(fd, buf, BUFFSIZE)) > 0) {
        if(write(STDOUT_FILENO, buf, n) != n) {
            perror("write error");
            return -1;
        }
    }
    if(n < 0){
        perror("read error");
        return -1;
    }
    return 0;
}


static int
cat(const char *file){
    int fd, result;
    if((fd = open(file, O_RDONLY)) < 0){
        return -1;
    }
    result = cat_read_write(fd);
    if(close(fd) != 0){
        return -1;
    }
    return result;
}


int
main(int argc, char *argv[]){
    int code;
    int i;
    if (argc > 1){
        for(i = 1; i < argc; i++){
            if(cat(argv[i]) == -1){
                perror("cat error");
                code = 1;
                continue;
            }
        }
    } else {
        if(cat_read_write(STDIN_FILENO) == -1){
            code = 1;
        }
    }
    return code;
}
