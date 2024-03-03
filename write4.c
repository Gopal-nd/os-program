#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    char *fifoFile  = "nyfile";
    mkfifo(fifoFile,0666);
    int fd = open(fifoFile,O_RDONLY);

    if(fd == -1){
        perror("Error opening file");
        exit(1);
    }

    char message[] = "Hello World";;
    write(fd,message,sixeof(message));
    close(fd);
    printf("Message sent: %s\n", message);
}