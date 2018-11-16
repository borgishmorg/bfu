#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 100
#define LEN 30
int main(){
	char** mass = (char**)malloc(sizeof(char*)*COUNT);
	char* str = (char*)malloc(sizeof(char)*LEN);
	
	int count = 0;
	int flag = 1;
	
	while(fgets(str, LEN, stdin)){
		if(!strcmp(str, "\n")) continue;
		flag = 1;
		for(int i = 0; i < count; i++) 
			if(!strcmp(mass[i], str)){
				flag = 0;
				break;
			}
		
		if(flag){
			mass[count] = (char*)malloc(sizeof(char)*LEN);
			strcpy(mass[count], str);
			count++;
		} 
	}
	
	for(int i = 0; i < count/2; i++) printf("%s", mass[i]);
	printf("\n");
	for(int i = count/2; i < count; i++) printf("%s", mass[i]);
	return 0;
}

/*
Kill troll
Fight squirrels
Spell casts

Kill troll
Eat carrot
*/
