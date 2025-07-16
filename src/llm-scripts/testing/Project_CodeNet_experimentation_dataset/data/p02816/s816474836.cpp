#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,a[maxn],b[maxn],c[maxn],d[maxn];
ull h[maxn],tmp,B[maxn];

vector <int> ans;

int main()
{
	n=read(); B[0]=1; rep(i,1,n) a[i]=read(),a[i+n]=a[i]; rep(i,1,n) b[i]=read();
	rep(i,1,2*n-1) c[i]=a[i]^a[i+1]; c[n]=a[1]^a[n];
	rep(i,1,n-1) d[i]=b[i]^b[i+1]; d[n]=b[1]^b[n];
	rep(i,1,n) tmp=tmp*233+d[i],B[i]=B[i-1]*233;
	rep(i,1,2*n) h[i]=h[i-1]*233+c[i];
	
	//rep(i,1,2*n) cout<<c[i]<<" "; cout<<endl;
	//rep(i,1,n) cout<<d[i]<<" "; cout<<endl<<endl;
	
	for(int i=1;i<=n;i++)
	{
		ull p=h[i+n-1]-h[i-1]*B[n];
		if(p==tmp) ans.pb(i-1);
	}
	for(int i=0;i<ans.size();i++) printf("%lld %lld\n",ans[i],b[1]^a[1+ans[i]]);
	return 0;
}