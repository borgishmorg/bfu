#include "vector.h"

void init(vector* v, int size){
	*v = (vector) malloc(VECTOR_SIZE);
	(*v)->size = size;
	(*v)->last = -1;
	(*v)->data = (void*) calloc((*v)->size, sizeof(void*));
}

void move(vector v){
	int new_size = v->size*3/2; 
	void** new_data = (void*) malloc(sizeof(void*)*new_size);
	for(int i = 0; i <= v->last; i++) new_data[i] = v->data[i];
	v->size = new_size;
	free(v->data);
	v->data = new_data;
}

void swap(void** a, void** b){
	void* tmp = *a;
	*a = *b;
	*b = tmp;
}

void push_back(vector v, void* data){
	if(v->last + 1 == v->size) move(v);
	v->data[++v->last] = data;
}

void* get(vector v, int index){
	return v->data[index];
}

int size(vector v){
	return v->last+1;
}

void add(vector v, int index, void* data){
	if(v->last + 1 == v->size) move(v);
	memmove(v->data+index+1, v->data+index, sizeof(void*)*(v->last-index+1));
	v->data[index] = data;
	v->last++;
}

void change(vector v, int index, void* data){
	v->data[index] = data;
}

void erase(vector v, int index){
	memmove(v->data+index, v->data+index+1, sizeof(void*)*(v->last-index));
	v->last--;
}

void clear(vector v){
	free(v->data);
	free(v);
}

void mqsort(void** data, int (*cmp)(const void*, const void*), int l, int r){
	if(l >= r) return;
	int m = l + rand()%(r-l+1), ll = l-1, rr = r+1;
	
	while(1){
		do ll++;
		while(cmp(data[ll], data[m]) < 0);
		
		do rr--;
		while(cmp(data[rr], data[m]) > 0);
		
		if(ll >= rr) break;
		
		swap(data + ll, data + rr);
	}
	
	mqsort(data, cmp, l, rr);
	mqsort(data, cmp, rr+1, r);
}

void sort(vector v, int (*cmp)(const void*, const void*)){
	mqsort(v->data,  cmp, 0, v->last);
}


void minit(matrix* m, int rows, int columns){
	*m = (matrix) malloc (MATRIX_SIZE);
	(*m)->rows = rows;
	(*m)->columns = columns;
	(*m)->vectors = (vector*)malloc(sizeof(vector)*columns);
	for(int i = 0; i < columns; i++){
		init((*m)->vectors+i, rows + 1);
		(*m)->vectors[i]->last = rows - 1;
	}
}

void mchange(matrix m, int row, int column, void* data){
	return change(m->vectors[column], row, data);
}

void* mget(matrix m, int row, int column){
	return get(m->vectors[column], row);
}

int columns(matrix m){
	return m->columns;
}

int rows(matrix m){
	return m->rows;
}

void addcolumn(matrix m, int index){
	
	vector* vs = (vector*) malloc(sizeof(vector)*(++(m->columns)));
	
	for(int i = 0; i < index; i++) vs[i] = m->vectors[i];
	init(vs+index, rows(m) + 1);
	for(int i = index + 1; i < m->columns; i++) vs[i] = m->vectors[i-1];
	
	free(m->vectors);
	m->vectors = vs;
}

void erasecolumn(matrix m, int index){
	vector* vs = (vector*) malloc(sizeof(vector)*((m->columns)-1));
	for(int i = 0; i < index; i++) vs[i] = m->vectors[i];
	for(int i = index + 1; i < m->columns; i++) vs[i-1] = m->vectors[i];
	clear(m->vectors[index]);
	free(m->vectors);
	m->vectors = vs;
	m->columns--;
}

void mclear(matrix m){
	for(int i = 0; i < m->columns; i++) clear(m->vectors[i]);
	free(m->vectors);
	free(m);
}
