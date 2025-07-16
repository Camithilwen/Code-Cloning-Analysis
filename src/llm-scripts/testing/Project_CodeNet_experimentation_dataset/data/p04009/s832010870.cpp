#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
#define gc getchar()
#define N 103
#define sint short
#define upd(x,y) (x=max(x,(short)(y)))
#define debug(x) cerr<<#x<<"="<<x
#define sp <<" "
#define ln <<endl
using namespace std;
inline int inn()
{
	int x,ch;while((ch=gc)<'0'||ch>'9');
	x=ch^'0';while((ch=gc)>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^'0');return x;
}
sint s[N][N],dp[N][N][N][N];char str[N][N];
inline sint S(int a,int b,int c,int d)
{
	if(a>c) swap(a,c);if(b>d) swap(b,d);
	return (short)(s[c][d]+s[a-1][b-1]-s[a-1][d]-s[c][b-1]);
}
int main()
{
	int n=inn(),m=inn(),x=0,y=0;sint ans=0;
	for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(str[i][j]=='E') x=i,y=j;
			else s[i][j]=(str[i][j]=='o');
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		s[i][j]=(short)(s[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1]);
	for(int a=x;a;a--) for(int b=y;b;b--)
		for(int c=x;c<=n;c++) for(int d=y;d<=m;d++)
		{
			ans=max(ans,dp[a][b][c][d]);int L=d-y+1,R=m-y+b,U=c-x+1,D=n-x+a;
			if(a>U) upd(dp[a-1][b][c][d],dp[a][b][c][d]+S(a-1,max(b,L),a-1,min(d,R)));
			if(b>L) upd(dp[a][b-1][c][d],dp[a][b][c][d]+S(max(a,U),b-1,min(c,D),b-1));
			if(c<D) upd(dp[a][b][c+1][d],dp[a][b][c][d]+S(c+1,max(b,L),c+1,min(d,R)));
			if(d<R) upd(dp[a][b][c][d+1],dp[a][b][c][d]+S(max(a,U),d+1,min(c,D),d+1));
		}
	return !printf("%d\n",(int)ans);
}