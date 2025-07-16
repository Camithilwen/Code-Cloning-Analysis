#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int cnt[100][100];
int32_t main()
{
	int n=in();
	int ans=0;
	for(int j=0;j<n;j++)
	{
		double x;
		cin>>x;
		int i=llround(x*1e9);
		int t=0,f=0;
		//cout<<i<<"\n";
		while(i%2==0)t++,i/=2;
		while(i%5==0)f++,i/=5;
		for(int x=max(18-t,0LL);x<70;x++)
		for(int y=max(18-f,0LL);y<70;y++)
		ans+=cnt[x][y];
		
		cnt[t][f]++;
	}
	cout<<ans;
	
}
