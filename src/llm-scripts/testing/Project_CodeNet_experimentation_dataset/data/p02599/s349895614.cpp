#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll> 

#define left 2*node+1
#define right left+1
#define mid (s+e>>1)

const ll N=5e5+5;
vector<ll> T[4*N];

void build(ll A[], ll node, ll s, ll e){
	if(s==e){
		T[node].push_back(A[s]);
		return;
	}
	build(A, left, s, mid);
	build(A, right, mid+1, e);
	merge(T[left].begin(), T[left].end(), T[right].begin(), T[right].end(), back_inserter(T[node]));
}

ll query(ll node,ll s, ll e, ll x, ll y){
	if(e<s || s>y || e<x)
		return 0;
	if(x<=s && e<=y){
		ll a=upper_bound(T[node].begin(), T[node].end(), y)-T[node].begin();
		return T[node].size()-a;
	}
	ll p1=query(left, s, mid, x, y);
	ll p2=query(right, 1+mid,e, x, y);
	return p1+p2;
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, q;
	cin>>n>>q;
	ll A[n];
	ll B[n];
	for(ll i=0;i<n;i++)
		cin>>A[i];
	map<ll,ll> M;
	for(ll i=n-1;i>=0;i--){
		if(M.count(A[i]))
			B[i]=M[A[i]];
		else
			B[i]=INT_MAX;
		M[A[i]]=i;
	}

	build(B,0,0, n-1);

	while(q--){
		ll x, y;
		cin>>x>>y;
		ll ans=query(0,0,n-1,x-1,y-1);
		cout<<ans<<"\n";
	}
	
}
