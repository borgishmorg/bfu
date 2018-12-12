#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define STR_LEN 100

int f = 1;

void signal_hadler(int signalno){
	int file_des;
	char myfifo[] = "fifo_file",
	     buf[STR_LEN];
	
	printf("Move me into the foreground and write some string:\n");
	fgets(buf, STR_LEN, stdin);
	
	
	file_des = open(myfifo, O_WRONLY);
	write(file_des, buf, STR_LEN);
	close(file_des);
	f = 0;
}

int main(int argc, char* argv[]){
	signal(SIGUSR1, signal_hadler);
	while(f);
	return 0;
}

