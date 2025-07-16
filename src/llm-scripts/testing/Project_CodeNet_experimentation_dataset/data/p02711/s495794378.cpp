#include<stdio.h>
 
int main(){
	int N;
	scanf("%d", &N);
	if( N%10==7 || (N%100)/10==7 || N/100==7)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}