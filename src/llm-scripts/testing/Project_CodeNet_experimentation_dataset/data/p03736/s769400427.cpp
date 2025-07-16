#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll INF=1e15;
const int MAX_N=1<<18;

int m;
ll dat[2][2*MAX_N-1];
 
void init(int m_){
	m=1;
	while(m<m_) m*=2;
	for(int i=0; i<2*m-1; i++){
		dat[0][i]=INF;
		dat[1][i]=INF;
	}
}
 
void update(int i, int k, ll a){
	k+=m-1;
	dat[i][k]=a;
	while(k>0){
		k=(k-1)/2;
		dat[i][k]=min(dat[i][k*2+1], dat[i][k*2+2]);
	}
}

ll query(int i, int a, int b, int k, int l, int r){
	if(r<=a || b<=l) return INF;
	if(a<=l && r<=b){
		return dat[i][k];
	}else{
		ll vl=query(i, a, b, k*2+1, l, (l+r)/2);
		ll vr=query(i, a, b, k*2+2, (l+r)/2, r);
		return min(vl, vr);
	}
}

int main()
{
	int n, q, a, b;
	cin>>n>>q>>a>>b;
	a--; b--;
	init(n);
	ll dp[200001];
	fill(dp, dp+n, INF);
	int x[200001];
	for(int i=0; i<q; i++){
		cin>>x[i];
		x[i]--;
	}
	if(q==1){
		cout<<min(abs(x[0]-b), abs(x[0]-a))<<endl;
		return 0;
	}
	dp[a]=min(dp[a], (ll)abs(x[0]-b));
	dp[b]=min(dp[b], (ll)abs(x[0]-a));
	update(0, a, dp[a]-a);
	update(1, a, dp[a]+a);
	update(0, b, dp[b]-b);
	update(1, b, dp[b]+b);
	for(int i=1; i<q; i++){
		ll mn=query(0, 0, x[i]+1, 0, 0, m)+(ll)x[i]-(ll)abs(x[i]-x[i-1]);
		mn=min(query(1, x[i], n, 0, 0, m)-(ll)x[i]-(ll)abs(x[i]-x[i-1]), mn);
		dp[x[i-1]]=min(dp[x[i-1]], mn);
		update(0, x[i-1], dp[x[i-1]]-x[i-1]);
		update(1, x[i-1], dp[x[i-1]]+x[i-1]);
	}
	ll s=0;
	for(int i=1; i<q; i++) s+=(ll)abs(x[i]-x[i-1]);
	ll ans=INF;
	for(int i=0; i<n; i++){
		ans=min(ans, dp[i]+s);
	}
	cout<<ans<<endl;
	return 0;
}