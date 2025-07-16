#include <stdio.h>
int main(){
	int A;
	int B;
	int C;
	
	scanf("%d %d %d",&A,&B,&C);
	if (A==B && B!=C && C!=A) {
		printf("Yes\n");
	}
	else if (A==C && A!=B && C!= B){
		printf("Yes\n");
	}
	else if (B==C && A!=B && C!=A){
		printf ("Yes\n");
	}
	else printf ("No\n");
	return 0;
}