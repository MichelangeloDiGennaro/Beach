#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include"thpool.h"
#include"functions.h"
#define PORT 8080 

int main (void){
    int opt = 1;
    int sock_server, new_socket;
    struct sockaddr_in address;        
    int addrlen = sizeof(address); 

    if((sock_server = socket(AF_INET, SOCK_STREAM, 0)) < 0){ //socket creation
        perror("socket failed");
        exit(EXIT_FAILURE);
    }    

    address.sin_family = AF_INET;   
    address.sin_addr.s_addr = INADDR_ANY;   //localhost connection 
    address.sin_port = htons( PORT );       

    
    if(setsockopt(sock_server, SOL_SOCKET, (SO_REUSEPORT | SO_REUSEADDR), &opt, sizeof(opt)) < 0){   //helps in reuse of address and port
        perror("setsockopt failed"); 
        exit(EXIT_FAILURE);
    } 


    if (bind(sock_server, (struct sockaddr *)&address,  sizeof(address))<0){ 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }

    if (listen(sock_server, 3) < 0){ 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 

    if((new_socket= accept(sock_server, (struct sockaddr *)&address, (socklen_t*)&addrlen) < 0)){
        perror("accept failed");
        exit(EXIT_FAILURE); 
    }
    
    char c[2048]; 
    memset(&c, 0, sizeof(c));
    recv(new_socket, &c, 2048, 0);
    printf("%s", c);
    // int valread = read(new_socket, c, 5000);
    // printf("messaggio scritto %s", c);

    return 0;
}

