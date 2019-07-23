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
    int sock_client;
    struct sockaddr_in address;  
    char* msg = "fanculoH";      
       
    if((sock_client = socket(AF_INET, SOCK_STREAM, 0)) < 0){ //socket creation
        perror("socket failed");
        exit(-1);
    }    

    address.sin_family = AF_INET;      //localhost connection 
    address.sin_port = htons( PORT );       

    if(inet_pton(AF_INET, "127.0.0.1", &address.sin_addr)<=0){ 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    }

    if (connect(sock_client, (struct sockaddr *)&address, sizeof(address)) < 0){ 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    send(sock_client , msg , strlen(msg) , 0 ); 
    printf("Hello message sent %s\n", msg);  
    return 0;  
    

    
    
}

