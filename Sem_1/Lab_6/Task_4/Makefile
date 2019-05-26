.PHONY: all client server

all: client server

client: bin src/client.c
	gcc -o bin/client.out src/client.c

server: bin src/server.c
	gcc -o bin/server.out src/server.c

bin:
	mkdir bin
