#include <stdio.h>
#include <math.h>

double power(double a, int n){
	if(n == 0) return 1;
	if(n == 1) return a;
	
	if(n < 0) return 1./power(a, -n);
	
	double b = power(a, n/2);
	if(n%2) return a*b*b;
	else return b*b;
}

double power_norec(double a, int n){
	int f = (n < 0);
	n = abs(n);
	double res = 1; 
	
	while(n>0){
		if(n%2) res*=a;
		a*=a;
		n/=2;
	}
	
	if(f) return 1/res;
	else return res;
}

void print(double a, int n){
	printf(" r: a = %5.5lf n = %5d  \nmy res = %.10lf\nmath.h = %.10lf\n\n", a, n, power(a, n), pow(a, n));
}
void print_norec(double a, int n){
	printf("nr: a = %5.5lf n = %5d  \nmy res = %.10lf\nmath.h = %.10lf\n\n", a, n, power(a, n), pow(a, n));
}
int main(){
	print(2, 0);
	print(2, -10);
	
	print_norec(2, 0);
	print_norec(2, -10);
	
	print(3.14159265358979, 100);
	return 0;
}
