#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

ll n,a[maxn],b[maxn],c[maxn];

inline ll read()
{
	ll x=0,w=1,x2=0,base=1e9; char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	if(c=='.')
	{
		while(c<'0'||c>'9') c=getchar();
		while(c<='9'&&c>='0') {x2=(x2<<1)+(x2<<3)+c-'0'; base/=10; c=getchar();}
		return x*1e9+x2*base;
	}
	else return x*1e9;
}

ll dp[55][55];

int main()
{
	ll n,ans=0; cin>>n; rep(i,1,n) a[i]=read();
	rep(i,1,n)
	{
		int c1=0,c2=0;
		while(a[i]%2==0) a[i]/=2,c1++; c1=min(18,c1);
		while(a[i]%5==0) a[i]/=5,c2++; c2=min(18,c2);
		rep(j,18-c1,50) rep(k,18-c2,50) ans+=dp[j][k];
		dp[c1][c2]++;
	}
	cout<<ans<<endl;
	return 0;
}