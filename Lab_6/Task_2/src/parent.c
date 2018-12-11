#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define PRINTED_JOKES_COUNT 3
#define JOKES_COUNT 10
#define JOKE_SIZE 300
#define JOKE_TIME 2000000

const char jokes_list[JOKES_COUNT][JOKE_SIZE] = {
	"An optimist says: \"the glass is half full.\"\n\nA pessimist says: \"the glass is half empty.\"\n\nA programmer says: \"the glass is twice as large as necessary.\"",
	"Definition, Algorithm: Word used by programmers when they do not want to explain what they did.",
	"I'd like to make the world a better place, but they won't give me the source code...", 
	"A programmer puts two glasses on his bedside table before going to sleep. A full one, in case he gets thirsty, and an empty one, in case he doesn’t.", 
	"Java and C were telling jokes. It was C's turn, so he writes something on the wall, points to it and says \"Do you get the reference?\" But Java didn't.", 
	"Software developers like to solve problems. If there are no problems available, they will create their own problems.", 
	"Definition, Programmer: An organism that turns caffeine and pizza into software.", 
	"The state of development in 2017: “Please don’t apply if you don’t have the core concepts of programming, and you depend upon copying and pasting the code from StackOverflow/saved file.”", 
	"Q: How many programmers does it take to screw in a light bulb?\n\nA: None. It's a hardware problem.", 
	"42?" 
};

void help(){
	printf("Usage: parent FILE\n");
}

void jokes(){
	int i;
	for(i = 0; i < PRINTED_JOKES_COUNT; i++){
		printf("%s\n\n\n", jokes_list[rand()%JOKES_COUNT+1]);
		usleep(JOKE_TIME);
	}
}

int main(int argc, char* argv[]){
	if(argc != 2){
		help();
		return 0;
	}
	
	pid_t pid = fork();
	
	if(pid){
		if(pid < 0){
			printf("I can't create a child !!");
			return 0;
		} 
		jokes();
		int childStatus;
		wait(&childStatus);
		printf("Child has finished his work\n");
	}else{
		char* path = (char*)malloc(sizeof(char)*PATH_MAX);
		getcwd(path, PATH_MAX);
		strcat(path, "/child.out");
		int res = execl(path, path, argv[1], (char*)NULL);
		printf("%d %s\n", res, path);
		free(path);
	}
	return 0;
}
