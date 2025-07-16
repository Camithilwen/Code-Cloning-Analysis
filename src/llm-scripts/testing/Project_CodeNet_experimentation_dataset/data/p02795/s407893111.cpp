#include <stdio.h>

int main(){
	int H, W, N, res;
	scanf("%d", &H);
	scanf("%d", &W);
	scanf("%d", &N);
	if(H>W){
		res = N/H;
		N%H > 0? res+=1 : res=res; 
	}
	else{
		res = N/W;
		N%W > 0? res+=1 : res=res; 
	}
	printf("%d\n", res);
	
	return 0;
}