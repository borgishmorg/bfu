#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print1(){
	int fileDiscriptor = open("file1.txt", O_WRONLY);
	
	if(fileDiscriptor < 0) return;
	
	int i;
	int buff_size = 20*1024*1024+1;
	char* buff = (char*)malloc(buff_size);
	
	for(i = 0; i < buff_size; i++) buff[i] = rand()%30 + '0';
	
	write(fileDiscriptor, buff, buff_size);
	
	free(buff);
}

void print2(){
	FILE* file = fopen("file2.txt", "w");
	
	int i;
	int buff_size = 20*1024*1024+1;
	
	//for(i = 0; i < buff_size; i++) fprintf(file, "%c", (char) rand()%30 + '0');
	for(i = 0; i < buff_size; i++) fputc( (char) rand()%30 + '0', file);
	
	fclose(file);
}

int main(int argc, char* argv[]){
	//print1();
	print2();
		
	return 0;
}
