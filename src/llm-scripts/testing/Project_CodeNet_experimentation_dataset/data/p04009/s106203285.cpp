#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define get(A,B,C,D) (rui[B][D]-rui[A-1][D]-rui[B][C-1]+rui[A-1][C-1])
short dp[102][102][102][102];
int map[100][100];
short rui[101][101];
int main()
{
	int mx,my;
	scanf("%d%d",&mx,&my);
	int sx,sy;
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			char z;
			scanf(" %c",&z);
			if(z=='o')map[i][j]=1;
			if(z=='E')sx=i,sy=j;
		}
	}
	for(int i=0;i<mx;i++)for(int j=0;j<my;j++)rui[i+1][j+1]=rui[i+1][j]+rui[i][j+1]-rui[i][j]+map[i][j];
	short maxi=0;
	for(int i=1;i<=mx;i++)
	{
		for(int j=mx;j>=i-1;j--)
		{
			for(int k=1;k<=my;k++)
			{
				for(int l=my;l>=k-1;l--)
				{
					short t=dp[i][j][k][l];
					maxi=max(maxi,t);
					if(i>j||k>l)continue;
					int si=1+sx-(mx-j);
					int sj=1+sx+(i-1);
					int sk=1+sy-(my-l);
					int sl=1+sy+(k-1);
					dp[i+1][j][k][l]=max(dp[i+1][j][k][l],t);
					dp[i][j-1][k][l]=max(dp[i][j-1][k][l],t);
					dp[i][j][k+1][l]=max(dp[i][j][k+1][l],t);
					dp[i][j][k][l-1]=max(dp[i][j][k][l-1],t);
					if(si<=i)dp[i+1][j][k][l]=max(dp[i+1][j][k][l],short(t+get(i,i,max(sk,k),min(sl,l))));
					if(sj>=j)dp[i][j-1][k][l]=max(dp[i][j-1][k][l],short(t+get(j,j,max(sk,k),min(sl,l))));
					if(sk<=k)dp[i][j][k+1][l]=max(dp[i][j][k+1][l],short(t+get(max(si,i),min(sj,j),k,k)));
					if(sl>=l)dp[i][j][k][l-1]=max(dp[i][j][k][l-1],short(t+get(max(si,i),min(sj,j),l,l)));
				}
			}
		}
	}
	printf("%d\n",maxi);
}
