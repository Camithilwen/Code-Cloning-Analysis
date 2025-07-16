#include<stdio.h>
int main()
{
	int a,b,c,n;
	scanf("%d %d %d",&n,&a,&b);
	if(n==2){
		for (int i=1; i < a ;i++) {
			if(a%i+b%i==0){
				printf("%d\n",i);
			}
		}
	}else if(n==3){
		scanf("%d",&c);
		for (int i=1; i < a ;i++) {
			if(a%i+b%i+c%i==0){
				printf("%d\n",i);
			}
		}
	}
	return 0;
}