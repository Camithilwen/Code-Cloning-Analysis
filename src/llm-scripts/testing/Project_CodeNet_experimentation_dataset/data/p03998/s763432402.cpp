/* When Talent doesn't work, Hard work beats Talent*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include"bits/stdc++.h"

using namespace std;

#define Fast_D cout<<fixed<<setprecision(2);
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define nl "\n"
#define sp " "
#define int long long
#define double long double
#define all(v) v.begin(),v.end()
#define scanstr(s) cin>>ws; getline(cin,s);

const double PI=3.141592653589793;

void solve()
{
	string s[3];
	for(int i=0;i<3;i++) cin >> s[i];
	for(auto &c : s) reverse(all(c));
	int cur=0;
	while(s[cur].size()>0)
	{
		int x=cur;
		cur=s[x].back() - 'a';
		s[x].pop_back();
	}
	char ans= 'A'+cur;
	cout << ans << nl;
}

int32_t main()
{
	FastIO;
	Fast_D;
	int T;
	T=1;
	while(T--)
	{
		solve();
	}
	return 0;
}
