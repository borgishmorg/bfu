#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VECTOR_SIZE sizeof(void**)+2*sizeof(int)
#define MATRIX_SIZE sizeof(void**)+2*sizeof(int)

typedef struct {
	void** data;
	int last;
	int size;
		
}* vector;

typedef struct{
	vector* vectors;
	int columns;
	int rows;
}* matrix;

void init(vector* v, int size);
void init_size(vector* v, int size);
void push_back(vector v, void* data);
void* get(vector v, int index);
int size(vector v);
void add(vector v, int index, void* data);
void change(vector v, int index, void* data);
void erase(vector v, int index);
void clear(vector v);
void sort(vector v, int (*cmp)(const void*, const void*));

void minit(matrix* m, int rows, int columns);
void mchange(matrix m, int row, int column, void* data);
void* mget(matrix m, int row, int column);
int columns(matrix m);
int rows(matrix m);
void addcolumn(matrix m, int index);
void erasecolumn(matrix m, int index);
void mclear(matrix m);
