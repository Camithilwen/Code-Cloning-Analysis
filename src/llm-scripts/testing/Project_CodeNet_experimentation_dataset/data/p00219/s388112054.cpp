#include<stdio.h>
int main(void)
{
	int n,x,cnt[10],i,j;
	while(1){
		for(i=0;i<10;i++){
			cnt[i]=0;
		}
		scanf("%d",&n);
		if(n<1)break;
		for(i=0;i<n;i++){
			scanf("%d",&x);
			cnt[x]++;
		}
		for(i=0;i<10;i++){
			if(cnt[i]>0){
				for(j=0;j<cnt[i];j++){
					printf("*");
				}
				printf("\n");
			}
			else{
				printf("-\n");
			}
		}
	}
	return 0;
}