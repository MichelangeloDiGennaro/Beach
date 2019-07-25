#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>
#include <sys/un.h> 
#include <sys/socket.h>
#include"thpool.h"
#include"functions.h"
#define N 7
#define SERVER_PATH "/tmp/server"

int main(void){
    unlink(SERVER_PATH);
    struct sockaddr_un stru;
    int sock_serv, new_sock;
    int opt = 1;
    struct sockaddr* cliaddr;
    threadpool th;

    cliaddr = malloc(sizeof(struct sockaddr));
    socklen_t addrlen = strlen((char* )cliaddr);

    if((sock_serv = socket(AF_UNIX, SOCK_STREAM, 0)) < 0){
        printf("socket creation error");
        exit(-1);
    }

    bzero(&stru, sizeof(struct sockaddr_in)); 
    
    stru.sun_family = AF_UNIX ;
    strncpy (stru.sun_path, SERVER_PATH, sizeof(stru.sun_path));
    
    if((bind(sock_serv, (struct sockaddr*) &stru , sizeof(struct sockaddr_un ))) < 0){
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }


    

    th = thpool_init(5);

    thpool_add_work(th, (void*)thread_master, NULL);
    thpool_wait(th);

    thpool_add_work(th, (void*)thread_worker, &sock_serv);

    close(sock_serv);
    close(new_sock);

    unlink(SERVER_PATH);
    return 0;
}