#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;//往左走w-1,往下走h-1 
const ll mod=1000000007;
ll f[1000000];
ll quick(ll a,ll b)
{
//	cout<<"a"<<a<<"b"<<b<<endl;
	ll ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=(ans*a)%mod;
		}
		b>>=1;
		a=(a*a)%mod;
	}
//	cout<<"("<<ans<<endl;
	return ans;
}
ll ni(ll a)
{
//	cout<<"ni"<<endl;
	return quick(a,mod-2);
}
ll c(int n,int m)
{
	ll a=f[n];
//	cout<<"a"<<f[n]<<endl;
	ll b=(f[m]*f[n-m])%mod;
//	cout<<"b"<<b<<endl;
	return (a*ni(b))%mod;
}
int main()
{
	int h,w,a,b;
	f[0]=1;
	for(int i=1;i<=200005;i++)
	{
		f[i]=(f[i-1]*i)%mod;
	}
	cin>>h>>w>>a>>b;
	ll ans=0;
	ll t;
	for(int i=b+1;i<=w;i++)
	{
	//	cout<<"-----"<<endl; 
	//	cout<<"!"<<c(h-a-1+i-1,h-a-1)<<endl;
	//	cout<<"!"<<c(w-i+a-1,a-1)<<endl;
		t=(c(h-a-1+i-1,h-a-1)*c(w-i+a-1,a-1))%mod;
		ans=(ans+t)%mod;
	}
	cout<<ans<<endl;
}