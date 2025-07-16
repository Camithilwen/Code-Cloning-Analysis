#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
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

ll n,x,a[maxn],F;

int main()
{
	n=read(); x=read(); rep(i,1,n) a[i]=read(); sort(a+1,a+n+1);
	ll tmp=0;
	rep(i,1,n)
	{
		tmp+=a[i];
		if(tmp==x) {F=1; cout<<i<<endl; break;}
		else if(tmp>x) {F=1; cout<<i-1<<endl; break;}
	}
	if(!F) cout<<n-1<<endl;
	return 0;
}