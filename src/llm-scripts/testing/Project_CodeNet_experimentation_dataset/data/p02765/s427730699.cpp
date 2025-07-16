#include<stdio.h>
int main()
{
	int N,R,A;
	scanf("%d %d", &N, &R);
	A =100*(10-N);
	if(N>=10){
		printf("%d", R);
	}
	else{
		printf("%d", R + A);
	}
return 0;
}