#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	long long int sum=0;
	long long int min =0;
	for (int i=1; i<= t; i++){
		if (i%3==0 || i%5==0){
			min += i;
		}
		sum+=i;
	}
	printf("%lld", sum-min);
	return 0;
}