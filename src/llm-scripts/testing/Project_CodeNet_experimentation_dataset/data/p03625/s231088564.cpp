#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int32_t main()
{
	int n=in();
	map<int,int> f;
	int x;
	vector<int> a;
	for(int i=0;i<n;i++){x=in();f[x]++;}
	for(auto i:f)
	{
		int t=i.second;
		t/=2;
		for(int _=0;_<t;_++)a.push_back(i.first);
	}
	sort(a.rbegin(),a.rend());
	if(a.size()<=1)cout<<0;
	else cout<<a[0]*a[1];
	
	
}