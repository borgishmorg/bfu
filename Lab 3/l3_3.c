#include <stdio.h>
#include <time.h>

#define MAX_RAND 2147483647

int rand(){
	long long a = 84589, c = 45989, i = 0, m = MAX_RAND;
	long long x = (time(NULL)%m+clock())%m;
	long long NMAX = x%100 + 100;
	while(i++ < NMAX) x = (a*x+c)%m;
	return x; 
}

int rand_int(int l, int r){
	return rand()%(r-l+1) + l;
}

double rand_double(){
	return ((double)(rand())/MAX_RAND);
}

int main(){
	
	printf("%d \n", rand_int(0, 100));
	printf("%.12lf\n", rand_double());
	
	return 0;
}
