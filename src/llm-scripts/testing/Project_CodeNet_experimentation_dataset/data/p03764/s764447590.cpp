#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define vll vector<ll>

using namespace std;

const ll N = 4e5+100;
const ll MOD = 1e9+7;
string s,t;
ll tree[N];

void build(ll node,ll l,ll r)
{
	if(l==r)
	{
		tree[node] = (s[l-1] == t[r-1]);
	}
	else
	{
		ll mid = (l + r) >> 1LL;
		build(node*2,l,mid);
		build(2*node+1,mid+1,r);
		tree[node] = tree[node*2] + tree[node*2+1];
	}
}

ll query(ll node,ll st,ll en,ll l,ll r)
{
	if(r < st || l> en) return 0;
	if(st >= l && en <= r) return tree[node];
	ll mid = (st + en)/2;
	ll p1 = query(node*2,st,mid,l,r);
	ll p2 = query(node*2+1,mid+1,en,l,r);
	return p1 + p2;
}

ll pre[N];
ll pr2[N];
int main()
{
	ll n,m;
	cin >> n >>m;
	ll a[n+1],b[m+1];

	for(int i =1;i<=n;i++) cin >>a[i-1];
	for(int i =1;i<=m;i++) cin >> b[i-1];

	ll co = 0,co2 = 0;

	for(int i =0;i<(n-1);i++)
	{
		ll x = i+1;
		co = co + ((a[i+1]- a[i]) * (x) * (n-x));
		if(co < MOD) co+=MOD;
		co%=MOD;
	}

	for(int i =0;i<(m-1);i++)
	{
		ll x = i+1;
		co2 = co2 + ((b[i+1]- b[i]) * (x) * (m-x));
		if(co2 < MOD) co2+=MOD;
		co2%=MOD;
	} 
	 		
	 cout << (co*co2) %MOD << endl;
	
	return 0;
}