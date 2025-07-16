#include <iostream>
using namespace std;

int main() {
	long long n,i,mod=1000000007LL;
	cin >> n;
	long long a[n+1],p[n+1],ans=0LL;
	p[0]=0;
	for(i=1;i<=n;i++)
	{
		cin >> a[i];
		p[i]=a[i]+p[i-1];
		p[i]%=mod;
	}
	for(i=1;i<=n;i++)
	{
		ans+=((p[n]-p[i])*a[i]);
		ans+=mod;
		ans%=mod;
	}
	cout << ans%mod;
	return 0;
}