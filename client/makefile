client: client.o thpool.o
	gcc -g -o  client -D THPOOL_DEBUG -pthread client.o thpool.o -lc

client.o: client.c functions.h thpool.h
	gcc -g -c -D THPOOL_DEBUG -pthread client.c

thpool.o: thpool.c thpool.h
	gcc -g -c -D THPOOL_DEBUG -pthread thpool.c