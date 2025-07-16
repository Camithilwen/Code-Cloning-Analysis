#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	long long mod=(1e+9)+7;
	long long n,m;
	cin>>n>>m;
	static long long sum_x,sum_y;
	vector<long long> x(n+10),y(m+10);
	for(ll i=1;i<=n;i++) cin>>x[i];
	for(ll i=1;i<=m;i++) cin>>y[i];
	for(ll xx=1;xx<=n;xx++){
		sum_x+=(2*xx-n-1)*x[xx];
		sum_x%=mod;
	}
	for(ll yy=1;yy<=m;yy++){
		sum_y+=(2*yy-m-1)*y[yy];
		sum_y%=mod;
	}
	cout<<(sum_x*sum_y)%mod<<endl;
}
