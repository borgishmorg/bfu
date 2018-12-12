#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>


#define PORT 5049
#define BUFSIZE 202500

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Usage: ./client DNS_NAME");
	}
	
	struct sockaddr_in local;
	inet_aton("127.0.0.1", &local.sin_addr);
	local.sin_port = htons(PORT);
	local.sin_family = AF_INET;
	int s = socket(AF_INET, SOCK_STREAM, 0);
	if(connect(s, (struct sockaddr*) &local, sizeof(local))){
		printf("I can't connect to socket");
		return 0;
	}
	char buf[BUFSIZE] = "";
	
	struct hostent *h;
	h = gethostbyname(argv[1]);

	
	int i = 0;
	while(NULL != h->h_addr_list[i]){
		struct in_addr* tmp = (struct in_addr*) h->h_addr_list[i];
		strcat(buf, inet_ntoa(*tmp));
		strcat(buf, "\n");
		i++;
	}
	
	send(s, buf, strlen(buf)+1, 0);
	close(s);
	
	return 0;
}

