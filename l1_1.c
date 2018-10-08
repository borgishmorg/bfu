#include <stdio.h>

int i;

int main(){
	
	for(i = 'A'; i <= 'Z'; i++) printf("%c %d\n", (char) i, i);
	for(i = 'a'; i <= 'z'; i++) printf("%c %d\n", (char) i, i);
	printf("' ' %d\n", ' ');
	printf("\\n %d\n", '\n');
	printf("Hello world!");
	return 0;
}
