#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 102
#define STR_COUNT 2000000

void sort(char** list, int l, int r){
	if(l >= r) return;
	int m = l, 
	    ll = l-1, 
	    rr = r+1;
	
	while(1){
		do ll++;
		while(strcmp(list[m], list[ll]) > 0);
		
		do rr--;
		while(strcmp(list[m], list[rr]) < 0);
		
		if(ll >= rr) break;
		
		char* tmp = list[ll];
		list[ll] = list[rr];
		list[rr] = tmp;
		
	}
	
	sort(list, l, rr);
	sort(list, rr+1, r);
}

int main(int argc, char* argv[]){
	if(argc != 2) return 0;

	int i;
	FILE* input = fopen(argv[1], "r");
	FILE* output = fopen("sorted_data", "w");
	
	char** list = (char**)malloc(sizeof(char*)*STR_COUNT);

	for(i = 0; i < STR_COUNT; i++){
		list[i] = (char*)malloc(sizeof(char)*STR_LEN);
		fgets(list[i], STR_LEN, input);
	} 
	sort(list, 0, STR_COUNT-1);
	for(i = 0; i < STR_COUNT; i++){
		fprintf(output, "%s", list[i]);
		free(list[i]);
	} 
	free(list);
	fclose(input);
	fclose(output);
	return 0;
}






