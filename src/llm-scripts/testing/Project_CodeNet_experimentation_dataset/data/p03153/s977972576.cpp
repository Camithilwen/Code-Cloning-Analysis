/*
 * RD
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define pii pair<int,int>
#define sz(x) ((int)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll inf=1e18;
const int mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//12367769,266916112,123798211
ll powm(ll a, ll b, ll m);

int n,d;
pii segtree1[400005];
pii segtree2[400005];
pii query1(int l, int r)
{
	r++;
	pii res={inf+1,inf};
	for(l+=n+1,r+=n+1; l<r; l>>=1,r>>=1)
	{
		if(l&1) res=min(res,segtree1[l++]);
		if(r&1) res=min(res,segtree1[--r]);
	}
	return res;
}
pii query2(int l, int r)
{
	r++;
	pii res={inf+1,inf};
	for(l+=n+1,r+=n+1; l<r; l>>=1,r>>=1)
	{
		if(l&1) res=min(res,segtree2[l++]);
		if(r&1) res=min(res,segtree2[--r]);
	}
	return res;
}
int a[200005];
int solve(int l, int r, int l1, int r1)
{
	if(l+1==r)
		return 0;
	pii lef=query1(l+1,r-1);
	pii rig=query2(l+1,r-1);
//	deb<<l<<" "<<r<<endl;
//	deb<<lef.fi<<" "<<lef.se<<" "<<rig.fi<<" "<<rig.se<<endl;
	ll ans=0;
	if(lef.fi+a[l1]-l1*d>rig.fi+a[r1]+r1*d)
	{
		ans+=rig.fi+a[r1]+r1*d;
		lef=rig;
	}
	else
		ans+=lef.fi+a[l1]-l1*d;
	if(a[lef.se]+lef.se*d<a[r1]+r1*d)
		ans+=solve(l,lef.se,l1,lef.se);
	else
		ans+=solve(l,lef.se,l1,r1);
	if(a[lef.se]-lef.se*d<a[l1]-l1*d)
		ans+=solve(lef.se,r,lef.se,r1);
	else
		ans+=solve(lef.se,r,l1,r1);
	return ans;
}
void solve()
{
	cin>>n>>d;
	for(int i=0; i<n; i++)
		cin>>a[i];
	a[n]=inf;
	for(int i=n+1; i<2*n+2; i++)
	{
		segtree1[i]={a[i-n-1]+(i-n-1)*d,i-n-1};
		segtree2[i]={a[i-n-1]-((i-n-1)*d),i-n-1};
	}
	for(int i=n; i>0; i--) {
		segtree1[i]=min(segtree1[i<<1],segtree1[i<<1|1]);
		segtree2[i]=min(segtree2[i<<1],segtree2[i<<1|1]);
	}
	cout<<solve(0,n,0,n)<<endl;
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	auto clk=clock();
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}
ll powm(ll a,ll b, ll m) {
	ll te=1;
	while(b) {
		if(b&1) te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}
