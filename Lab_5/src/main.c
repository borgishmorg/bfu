#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

void print(vector v){
	printf("\nsize: %d last: %d", size(v), v->last);
	for(int i = 0; i < size(v); i++) printf("\n%4d: %4d ", i, *((int*)get(v, i)));
	printf("\n");
}

void mprint(matrix m){
	printf("\nrows: %d columns: %d\n", rows(m), columns(m));
	for(int i = 0; i < rows(m); i++){
		for(int j = 0; j < columns(m); j++){
			fflush(stdout);
			printf("%4d", *((int*)mget(m, i, j)));
		}
			
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char* argv[]){
	vector v;
	init(&v, 5);
	int mass[1000];
	mass[100] = 0;
	for(int i = 0; i < 50; i++){
		mass[i] = rand()%97;
		add(v, 0, mass+i);
		if(i%2) erase(v, 0);
	}
	print(v);
	sort(v, cmp);
	print(v);	
	printf("\n%d ", VECTOR_SIZE);
	
	matrix m;
	minit(&m, 15, 20);
	for(int i = 0; i < rows(m); i++)
		for(int j = 0; j < columns(m); j++)
			mchange(m, i, j, mass+(i+j)%50);
	mprint(m);
	
	addcolumn(m, 2);
	for(int i = 0; i < rows(m); i++) mchange(m, i, 2, mass+100);
	addcolumn(m, 0);
	for(int i = 0; i < rows(m); i++) mchange(m, i, 0, mass+100);
	addcolumn(m, 10);
	for(int i = 0; i < rows(m); i++) mchange(m, i, 10, mass+100);
	mprint(m);
	
	erasecolumn(m, 0);
	erasecolumn(m, 0);
	erasecolumn(m, 0);
	erasecolumn(m, 0);
	
	mprint(m);
	mclear(m);
	return 0;
}



