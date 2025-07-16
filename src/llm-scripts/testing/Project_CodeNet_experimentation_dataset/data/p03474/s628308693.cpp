#include<stdio.h>
int main(){
	int A, B;
	int mark =0;
	scanf("%d %d", &A, &B);
	char in[A+B+1];
	scanf("%s", in);
	int ctr = 0;
	for(int i = 0; i < A+B+1 ; i++){
		if(in[i] == '-' && i == A){
			mark = 1;
		}else if(in[i] >= '0' && in[i] <= '9' ){
			++ctr;
		}
	}
	if( mark == 1 && ctr == A+B){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
	return 0;
}