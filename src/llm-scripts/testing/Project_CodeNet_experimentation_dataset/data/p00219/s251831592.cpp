#include<stdio.h>
int main()
{
	int n,a[10],b,i,j;
	while(1){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		for(i=0;i<10;i++){
			a[i]=0;
		}
		for(i=0;i<n;i++){
			scanf("%d",&b);
			a[b]++;
		}
		for(i=0;i<10;i++){
			if(a[i]==0){
				printf("-");
			}
			else{
				for(j=0;j<a[i];j++){
					printf("*");
				}
			}
			printf("\n");
		}
	}
	return 0;
}