//Author: ReseeCher
#include<bits/stdc++.h>
#define LL long long
#define F(x,y,z) for(int x=y;x<=z;++x)
#define D(x,y,z) for(int x=y;x>=z;--x)
#define ckmax(a,b) (a)=max(a,b)
#define ckmin(a,b) (a)=min(a,b)
#define pb push_back
#define Ad(x,y) (x)=((x)+(y))%P
using namespace std;
const int N=305;
const int P=998244353;
LL R(){
    LL ans=0,f=1;char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if (c=='-') f=-1;
    for(;c>='0'&&c<='9';c=getchar()) ans=ans*10+c-'0';
    return ans*f;
}
int a[N],n,m;
LL dp[N][N][N];
char s[N];
LL an[N];
int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	cin>>(s+1);int len=strlen(s+1);
	int K=R();
	++n;
	F(i,1,len)
		if(s[i]=='1')++a[n],++m;
		else ++n;
	
	dp[0][0][0]=1;
	F(i,0,n-1)
		F(j,0,m)
			F(k,0,m){
				if(!dp[i][j][k])continue;
				int lim=min(m+a[i+1]-j,min(m+a[i+1]-k,m));
				F(u,max(a[i+1]-j,0),lim){
					Ad(dp[i+1][j+(u-a[i+1])][k+max(0,u-a[i+1])],dp[i][j][k]);
				}
			}
	F(i,0,m)an[i]=dp[n][0][i];
	F(i,1,m)Ad(an[i],an[i-1]);
	cout<<an[min(K,m)];
    return 0;
}
