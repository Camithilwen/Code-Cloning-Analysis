#include<stdio.h>


int main(){
	
	int N;
	int R;
	scanf("%d %d",&N,&R);
	int x;
	x = 10 - N;
	int inner;
	inner = 100 * x;
	
	if(N>100 || N<1 || R<0 || R>4111){
		printf("eror");
	}
	else if(N<10){
		printf("%d",inner + R);
	}
	else if(N>=10){
		printf("%d",R);
	}
	
	
	
	
	return 0;
}