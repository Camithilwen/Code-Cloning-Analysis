#include<bits/stdc++.h>
using namespace std;
int line[110][110],col[110][110];
short dp[101][101][101][101];
int main()
{
	int n,m,x,y;scanf("%d%d\n",&n,&m);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		line[i][j]=line[i][j-1];col[i][j]=col[i-1][j];
		char ch=getchar();
		if (ch=='E') {x=i;y=j;}
		else if (ch=='o') {line[i][j]++;col[i][j]++;}
		if (j==m) scanf("\n");
	}
	
	int all=0;
	for (int i=x;i>=1;i--)
	for (int j=y;j>=1;j--)
	for (int k=x;k<=n;k++)
	for (int l=y;l<=m;l++)
	{
		all=max(all,(int)dp[i][j][k][l]);
		if ((1<i)&&(k+1<x+i)) dp[i-1][j][k][l]=max((int)dp[i-1][j][k][l],dp[i][j][k][l]+line[i-1][min(l,m-y+j)]-line[i-1][max(j-1,l-y)]);
		if ((k<n)&&(x+k<n+i)) dp[i][j][k+1][l]=max((int)dp[i][j][k+1][l],dp[i][j][k][l]+line[k+1][min(l,m-y+j)]-line[k+1][max(j-1,l-y)]);
		if ((1<j)&&(l+1<y+j)) dp[i][j-1][k][l]=max((int)dp[i][j-1][k][l],dp[i][j][k][l]+col[min(k,n-x+i)][j-1]-col[max(i-1,k-x)][j-1]);
		if ((l<m)&&(y+l<m+j)) dp[i][j][k][l+1]=max((int)dp[i][j][k][l+1],dp[i][j][k][l]+col[min(k,n-x+i)][l+1]-col[max(i-1,k-x)][l+1]);
	}
	cout<<all<<endl;
}