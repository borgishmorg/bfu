#include "vector.h"

void init(vector* v){
	*v = (vector) malloc(sizeof(vector));
	(*v)->size = 10;
	(*v)->last = -1;
	(*v)->data = (void*) malloc(sizeof(void*)*(*v)->size);
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

void erase(vector v, int index, void* data){
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


//===========================================================================

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

int main(int argc, char* argv[]){
	freopen("output.txt", "w", stdout);
	vector v;
	init(&v);
	int mass[1000];
	for(int i = 0; i < 50; i++){
		mass[i] = rand()%97;
		add(v, 0, mass+i);
		if(i%2) erase(v, 0, mass+i);
	}
	print(v);
	sort(v, cmp);
	print(v);	
	printf("\n%d ", v->size);
	
	return 0;
}



