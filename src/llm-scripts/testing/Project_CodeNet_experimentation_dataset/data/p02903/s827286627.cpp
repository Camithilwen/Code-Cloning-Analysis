#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int h,w,A,B;
int a[N][N];
int main()
{
	scanf("%d%d%d%d",&h,&w,&A,&B);
	for(int i=1;i<=B;i++)
		for(int j=1;j<=A;j++)
			a[i][j]=1;
	for(int i=B+1;i<=h;i++)
		for(int j=A+1;j<=w;j++)
			a[i][j]=1;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
			printf("%d",a[i][j]);
		printf("\n");
	}
	return 0;
}