#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int f(ll a,ll b)
{
	return (int)max(log10(a),log10(b));
}

int main()
{
	ll N;
	cin>>N;
	int ans=10;
	for(int i=1;i<sqrt(N)+1;i++)
	{
		if(N%i!=0) continue;
		ll k=N/i;
		int v=f(i,k);
		ans=min(ans,v);
	}
	cout<<ans+1<<endl;
	return 0;
}
