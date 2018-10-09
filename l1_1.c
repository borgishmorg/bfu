#include <stdio.h>

int main(){
	int i;
	for(i = 'A'; i <= 'Z'; i++) printf("%c %d\n", (char) i, i);
	for(i = 'a'; i <= 'z'; i++) printf("%c %d\n", (char) i, i);
	printf("' ' %d\n", ' ');
	printf("\\n %d\n", '\n');
	printf("Hello world!");
	return 0;
}
