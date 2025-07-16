#include<stdio.h>
int main(){
	int n, r, t;
	scanf("%d %d", &n, &r);
	t = 100 * (10 - n);
	if(n<10){
		printf("%d\n", r+t);
	}
	else{
		printf("%d\n", r);
	}
	return 0;
}
