#include<stdio.h>
#include<string.h>
int main(void)
{
	int a,s,d[10],f,g,h,j,i;
	scanf("%d",&a);
	while(a!=0){
		for(i=0;i<10;i++){
			d[i]=0;
		}
		for(i=1;i<=a;i++){
			scanf("%d",&s);
			d[s]++;
		}
		for(i=0;i<10;i++){
			if(d[i]!=0){
				for(j=1;j<=d[i];j++){
					printf("*");
				}
			}
			if(d[i]==0){
				printf("-");
			}
			printf("\n");
		}
		scanf("%d",&a);
	}
	return 0;
}