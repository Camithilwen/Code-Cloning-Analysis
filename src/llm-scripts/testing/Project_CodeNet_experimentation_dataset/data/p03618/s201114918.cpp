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
int f[26];
const int N=2e5+4;
int32_t main()
{
	string s;
	cin>>s;
	int n=s.length();
	int ans=1;
	for(int i=0;i<n;i++)
	{
		int cur=s[i]-'a';
		int len=i+1;
		
		ans+=i-f[cur];
		f[cur]++;
	}
	cout<<ans;
}
