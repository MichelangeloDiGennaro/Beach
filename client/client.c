#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>
#include <sys/un.h> 
#include <sys/socket.h>
#include <errno.h>
#include "thpool.h"
#include "functions.h"
#define SERVER_PATH "/tmp/server"

int  main(void){

    int sock_cl;
    struct sockaddr sa;
    
    if((sock_cl = socket(AF_UNIX, SOCK_STREAM, 0)) < 0){
        perror("socket creation error");
        exit(EXIT_FAILURE); 
    }
    
    sa.sa_family = AF_UNIX ;
    strncpy (sa.sa_data, SERVER_PATH, sizeof(sa.sa_data));

    if (connect(sock_cl , (struct sockaddr*)&sa , sizeof(sa)) == -1) {
        perror("connection to the server failed");
        exit(EXIT_FAILURE);             
    }
    
    write (sock_cl, "Hello!", 7);
    printf("message sended\n");
    close(sock_cl);

    return 0;
}