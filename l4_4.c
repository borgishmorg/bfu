#include <stdio.h>
#include <math.h>

#define N 1000

double f2(double x){
	return x*cos(x);
}
double f3(double x){
	return x*x+x-tan(x);
}
double f4(double x){
	return exp(x)+3;
}

double integral(double (*f)(double), double a, double b, double c){
	double res = 0;
	double d = (b - a)/N;
	
	for(int i = 0; i < N; i++) res += (f(a+d*i) - c)*d;
	return res;
}

int main(){
	double (*fs[4])(double) = {sin, f2, f3, f4};
	
	double s, a, b, c, ans = -1e100, u;
	
	scanf("%lf %lf %lf %lf", &s, &a, &b, &c);
	
	for(int i = 0; i < 4; i++){
		u = integral(fs[i], a, b, c);
		
		if(u > ans && u <= s) ans = u;
	}
	
	printf("%lf", ans);
	
	return 0;
}
