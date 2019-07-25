#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>
#include <sys/un.h> 
#include <sys/socket.h>

void thread_master();
void thread_worker(int);