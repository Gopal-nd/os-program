#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

void main(){
    int buffer[10], bufsize, in, out, producer , consumer, choice = 0;

    in = 0;
    out = 0;
    bufsize = 10;
    while(choice!=3){
        printf("1 produce 2 consume 3 exit");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if((in+1)%bufsize==out){
                    printf("Buffer is full\n");
                }
                else{
                    printf("Enter the data:");
                    scanf("%d", &buffer[in]);
                    in = (in+1)%bufsize;
                }
                break;
            case 2:
                if(in==out){
                    printf("Buffer is empty\n");
                }
                else{
                    printf("Data consumed is %d\n", buffer[out]);
                    out = (out+1)%bufsize;
                }
                break;
        }
    }
}