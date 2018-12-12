#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 5049 
#define BUFSIZE 2025

FILE* file;

void my_signal_handler(int signo){
	fclose(file);
	exit(0);
}

int main(int argc, char* argv[]){
	signal(SIGUSR1, my_signal_handler);
	
	file = fopen("received_data", "a");
	
	struct sockaddr_in local;
	inet_aton("127.0.0.1", &local.sin_addr);
	local.sin_port = htons(PORT);
	local.sin_family = AF_INET;
	int s = socket(AF_INET, SOCK_STREAM, 0);
	
	if(bind(s, (struct sockaddr*) &local, sizeof(local))){
		printf("Can't bind name to the socket!!!\n");
		return 0;
	}
	listen(s, 10);
	
	char buf[BUFSIZE];
	printf("I,m ready to receive\n");
	while(1){
		int cs = accept(s, NULL, NULL);
		read(cs, buf, BUFSIZE);
		printf("Receved:\n%s", buf);
		fprintf(file, "%s", buf);
	}
	
	return 0;
}

