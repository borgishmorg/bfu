#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 100
#define STR_COUNT 2000000
#define MIN_C 48
#define MAX_C 122

int main(int argc, char* argv[]){
	FILE* file = fopen("unsorted_data", "w");	
	int i, j, slen;
	for(i = 0; i < STR_COUNT; i++){
		slen = rand()%(MAX_STR_LEN-1)+1;
		for(j = 0; j < slen; j++) fprintf(file, "%c", rand()%(MAX_C-MIN_C+1)+MIN_C);
		fprintf(file, "\n");
	}
	
	fclose(file);
	return 0;
}
