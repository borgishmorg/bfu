#include <stdio.h>

#define NMAX 100
long long f[NMAX+1], n = 92, i;
int main(){
	f[0] = 0;
	f[1] = 1;
	for(i = 2; i <= n; i++) f[i] = f[i-1] + f[i-2];
	for(i = 0; i <= n; i++) printf("%2lld: %20lld\n", i, f[i]);

	return 0;
}
