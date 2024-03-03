#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    int status;

    pid = fork();   

    if(pid<0){
        perror("fork error");
        exit(1);
    
    }else if(pid ==0){

        printf("child process %d",getpid());
        char arg[] = {"eco","marthi",NULL};
        execv(arg[0],arg);
        perror("exec error");
        exit(1);
    }else{
        printf("parent process %d and %d", getpid(),pid);

        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child process exited with status: %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process terminated abnormally\n");
        }

        printf("Parent process exiting\n");
        exit(EXIT_SUCCESS);
    }

} 