#include<iostream>
#include<cstdio>
using namespace std;
int main(void)
{while(1)
{
	int  n=0;
	scanf("%d",&n);
	if(n==0){break;}
	int c=0,m[11]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c);
		for(int j=0;j<11;j++)
		{
			if(c==j){m[j]++;break;}
		}
	}
	for(int i=0;i<10;i++)
	{
		if(m[i]==0){printf("-");}
		else
		{
		for(m[i]=m[i];m[i]>0;m[i]--)
		{
			printf("*");
		}
}
		printf("\n");
	}
}
	return 0;
}
