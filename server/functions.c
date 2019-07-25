#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>
#include <sys/un.h> 
#include <sys/socket.h>
#include <semaphore.h>
#include"thpool.h"
#include"functions.h"

sem_t mutex;

void thread_master(){
    printf("analisi file di testo\n");
}

void thread_worker(int sock_serv){
    int select;
    if(listen(sock_serv, SOMAXCONN) < 0){
        perror("listen error\n");
        return 0;
    }
    int new_sock;
    if((new_sock = accept(sock_serv, NULL, 0)) < 0){
        perror("accept error\n");
        return 0;
    }
    printf("What do you want to do?\n");
    printf("1_BOOK\n");
    printf("2_EXIT\n");
    printf("Type the corrispondent number\n");
    read(new_sock, &select, sizeof(int));
    printf("choosen %d", select);

}