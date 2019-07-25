#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include"thpool.h"


sem_t mutex, receive_order, send_order;
int go = 1;
int sec = 10;

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
} 

void thread_boss(){

     
        printf("I AM THE BOOSSSSS\n");
   
        wait(&sec);
    
}

void thread_worker(){

       
   
        printf("i'm a poor worker\n");
       
        wait(&sec);

}


int main(void){
    sem_init(&mutex, 0, 1);
    sem_init(&receive_order, 0, 1);
    sem_init(&send_order, 0, 0);
    threadpool thpool = thpool_init(2);

   
        thpool_add_work(thpool, (void*)thread_boss, NULL);
        thpool_wait(thpool);
        thpool_add_work(thpool, (void*)thread_worker, NULL);
        thpool_wait(thpool);
    return 0;
}