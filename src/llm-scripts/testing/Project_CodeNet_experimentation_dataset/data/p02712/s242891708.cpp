#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	long long int total = 0;
	
	for (int i = 1; i <= n; i++){
		if (i % 3 != 0 && i % 5 != 0){
			total += i;
		}
	}
	printf("%lld", total);

}