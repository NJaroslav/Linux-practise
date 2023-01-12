#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();
    if (pid==-1){
        perror("Unable to fork\n");
        return 0;
    } else if(pid > 0){
        printf("[parent] My PID is %d\n",getpid());
        printf("[parent] Child's PID is %d\n",pid);
        int status;
        waitpid(pid, &status, 0);
        if(WIFEXITED(status)) {
            printf("[parent] Child exited with code %d\n", WEXITSTATUS(status));
        }
    } else {
        printf("[child] Hello, my PID is %d\n", getpid());
        sleep(1);
        printf("[child] Bye\n");
        _exit(42);
    }

    return 0;
}
