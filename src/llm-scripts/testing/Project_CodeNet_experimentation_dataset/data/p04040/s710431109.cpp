#include<iostream>
#include<cstring>
const int mod=1000000007;
using namespace std;
long long npow(long long x)
{
	long long ans=1,n=mod-2;
	while(n)
	{
		if(n&1) ans=ans*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ans;
}
long long co(long long x,long long y)
{
	long long ans=1;
	for(int i=0;i<x;i++)
		ans=(ans*(y-i))%mod;
	for(int i=0;i<x-1;i++)
		ans=(ans*npow(x-i))%mod;
	return ans;
}
int main()
{
	long long h,w,a,b,c1=1,c2,ans=0;
	cin>>h>>w>>a>>b;
	c1=1;
	c2=co(h-1,h+w-b-2);
	ans=(ans+c1*c2%mod)%mod;
	for(int i=2;i<=h-a;i++)
	{
		c1=(c1*(i+b-2)%mod*npow(i-1))%mod;
		c2=(c2*(h-i+1)%mod*npow(h-i+w-b))%mod;
		ans=(ans+c1*c2%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
 } 