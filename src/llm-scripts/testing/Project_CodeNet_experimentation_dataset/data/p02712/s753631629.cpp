#include <stdio.h>

int main(){
	long long N, sum;
	scanf("%lld", &N);
	sum = N*(N+1)/2;

	long long Un3 = N/3;
	long long Sn3 = 3*(Un3*(Un3+1)/2);
	
	long long Un5 = N/5;
	long long Sn5 = 5*(Un5*(Un5+1)/2);
	
	long long Un15 = N/15;
	long long Sn15 = 15*(Un15*(Un15+1)/2);

	printf("%lld", sum-Sn3-Sn5+Sn15);
			
	return 0;
}