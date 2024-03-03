#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(){
    char *fifoFile = "myfile";
    mkfifo(fifoFile, 0666);

    int fd = open(fifoFile,O_RDONLY);

    if(fd == -1){
        perror("error in opening");
        exit(1);
    }
    char message[100];
    read(fd, message, sizeof(message));

    printf("message: %s\n", message);
    colse(fd);
    return 0;
}