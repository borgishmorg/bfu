#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	void** data;
	int last;
	int size;
		
}* vector;

void init(vector* v);
void push_back(vector v, void* data);
void* get(vector v, int index);
int size(vector v);
void add(vector v, int index, void* data);
void change(vector v, int index, void* data);
void erase(vector v, int index, void* data);
void clear(vector v);
void sort(vector v, int (*cmp)(const void*, const void*));

