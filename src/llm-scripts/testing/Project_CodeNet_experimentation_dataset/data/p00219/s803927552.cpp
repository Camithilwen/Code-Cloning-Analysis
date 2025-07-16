#include <stdio.h>

int main(void)
{
	int a[10]={0};
	int n,i,j,k,l,x;
	
	for(j=0;j<20;j++)
	{
		//printf("?????°???");
		for(l=0;l<10;l++)
		a[l]=0;
		scanf("%d",&n);
		if(n==0)
		break;
		
		else
		{
			for(i=0;i<n;i++)
			{
				scanf("%d",&x);
				a[x]=a[x]+1;
			}
		}
	for(k=0;k<10;k++)
	{
		if(a[k])
		{
			for(l=0;l<a[k];l++)
			{
				printf("*");
			}
			printf("\n");
		}
		else printf("-\n");
	}
	}
	return 0;
}