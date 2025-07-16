#include <stdio.h>

int main(){
	
	int H1,H2,M1,M2,K;
	
	scanf("%d %d %d %d %d",&H1,&M1,&H2,&M2,&K);
	
	int sum1 = (H1*60) + M1;
	int sum2 = (H2*60) + M2;
	
	int sum3 = sum2 - sum1;
	 
	printf("%d", sum3 - K);
	
	return 0;
}