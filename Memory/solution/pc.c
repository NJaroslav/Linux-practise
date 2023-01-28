#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int src_fd;
    int dest_fd;
    void *src_addr, *dest_addr;
    off_t i;

    if(argc != 3) {
        printf("input");
        return 1;
    }

    if((src_fd = open(argv[1], O_RDONLY)) == -1) {
        perror("open source file");
        return 1;
    }   
    
    struct stat src_stat;
    if(fstat(src_fd, &src_stat) == -1) {
        perror("fstat source file");
        close(src_fd);
        return 1;
    }  

    if((dest_fd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, src_stat.st_mode)) == -1) {
        perror("open destination file");
        close(src_fd);
        return 1;
    }

    if(ftruncate(dest_fd, src_stat.st_size) == -1) {
        perror("ftruncate destination file");
        close(src_fd);
        close(dest_fd);
        return 1;
    }    

    if((src_addr = mmap(NULL, src_stat.st_size, PROT_READ, MAP_PRIVATE, src_fd, 0)) == MAP_FAILED) {
        perror("mmap source file");
        close(src_fd);
        close(dest_fd);
        return 1;
    }

    if((dest_addr = mmap(NULL, src_stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, dest_fd, 0)) == MAP_FAILED) {
        perror("mmap destination file");
        munmap(src_addr, src_stat.st_size);
        close(src_fd);
        close(dest_fd);
        return 1;
    }

    for(i = 0; i <= src_stat.st_size / 2; ++i) {
        char tmp = ((char *)src_addr)[i];
        ((char *)dest_addr)[i] = ((char *)src_addr)[src_stat.st_size - i - 1];
        ((char *)dest_addr)[src_stat.st_size - i - 1] = tmp;
    }

    munmap(src_addr, src_stat.st_size);
    munmap(dest_addr, src_stat.st_size);
    close(src_fd);
    close(dest_fd);
    return 0;
}
