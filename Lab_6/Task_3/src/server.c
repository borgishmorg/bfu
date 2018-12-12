#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

#define STR_LEN 100

int main(int argc, char* argv[]){
	int file_des;
	char* myfifo = "fifo_file";
	char buf[STR_LEN];
	
	mkfifo(myfifo, 0666);
	file_des = open(myfifo, O_RDONLY);
	
	read(file_des, buf, STR_LEN);
	
	int i;
	printf("\nReceived string:\n");
	for(i = 0; i < 10; i++) printf("%s", buf);
	
	close(file_des);
	unlink(myfifo);
	return 0;
}

