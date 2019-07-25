server: server.o thpool.o
	gcc -g -o  server -D THPOOL_DEBUG -pthread server.o thpool.o -lc

server.o: server.c functions.h thpool.h
	gcc -g -c -D THPOOL_DEBUG -pthread server.c

thpool.o: thpool.c thpool.h
	gcc -g -c -D THPOOL_DEBUG -pthread thpool.c