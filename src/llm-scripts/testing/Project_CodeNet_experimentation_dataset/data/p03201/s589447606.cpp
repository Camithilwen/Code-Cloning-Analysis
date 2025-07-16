
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ls( s) (s&(-s))
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e5+5;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =    2019;
int n;
ll ans=0;
multiset<ll> ms;
int main()
{  fast
cin>>n;

vector<ll> v(n);
for(auto&x:v)cin>>x;
for(auto x: v)ms.insert(x);
while(!ms.empty())
{
	ll val=*ms.rbegin();
	ms.erase(ms.find(val));ll y;
	for( y=1;y<=val;y*=2);
		auto it=ms.find(y-val);
		if(it!=ms.end())
		{
			ans++;
			ms.erase(it);

		}
}
cout<<ans;
}
