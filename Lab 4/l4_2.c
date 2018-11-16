#include <stdio.h>
#include <stdlib.h>

#define LEN 3

int main(){
	char* format = (char*) malloc(sizeof(char)*30);
	char* key = (char*) malloc(sizeof(char)*30);
	char* tmp = (char*) malloc(sizeof(char)*30);
	char* file_name = (char*) malloc(sizeof(char)*30);
	FILE* file;
	
	int max_num = 1;
	for(int i = 0; i < LEN; i++) max_num*=10; 
	
	sprintf(format, "%%0%dd.txt", LEN);
	
	file = fopen("input.txt", "r");
	fscanf(file, "%s", key);
	fclose(file);
	
	for(int i = 0; i < max_num; i++){
		sprintf(file_name, format, i);
		file = fopen(file_name, "r");
		if(file == NULL) continue;
		fscanf(file, "%s", tmp);
		if(!strcmp(tmp, key)) printf("%s\n", file_name);
		fclose(file);
	}
	return 0;
}
