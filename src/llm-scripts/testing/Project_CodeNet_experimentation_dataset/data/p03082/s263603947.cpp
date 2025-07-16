#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define ll long long
using namespace std;
ll dp[210][100009];
int ka[214514],inv[214514];
void setkaijo(int n){
	ka[0]=1;
	for(int i=1;i<=n;i++){
		ka[i] = ka[i-1] * i;
		ka[i] %= inf;
	}
}
int modpow(int x,int k){
	// x ^ k mod inf
	int p2[55],res=1;
	p2[0]=1;p2[1]=x%inf;
	for(int i=2;i<=50;i++){
		p2[i]=p2[i-1]*p2[i-1];
		p2[i] %= inf;
	}
	for(int i=1;i<=50;i++){
		if(k%2==1){
			res *= p2[i];
			res %= inf;
		}
		k /= 2;
	}
	return res;
}
void setinv(int n){
	for(int i=0;i<=n;i++){
		inv[i] = modpow(ka[i],(ll)inf-2);
	}
}
int comb(int n,int k){
	if(k>n)return 0;
	if(k==0 || k==n)return 1;
	int res = (ka[n] * inv[k]) % inf;
	res = (res*inv[n-k]) % inf;
	return res;
}
signed main(){
	ll n,x;
	cin>>n>>x;
	vector<ll> a;
	map<ll,ll> mope;
	setkaijo(100009);
	setinv(100009);
	for(int i=0;i<n;i++){
		ll tx;
		cin>>tx;
		a.pb(tx);
		mope[tx]++;
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	vector< pair<ll,ll> > v;
	for(int i=0;i<n;i++){
		if( mope[ a[i] ] != 0){
			v.pb( mp( a[i], mope[a[i]]) );
			mope[a[i]] = 0;
		}
	}
	dp[0][x] = 1;
	ll rem = n;
	for(int i=0;i<v.size();i++){
		ll md = v[i].first;
		ll num = v[i].second;
		ll cb = comb(rem-1,num-1);
		ll cb2 = comb(rem-1,num);
		for(int j=0;j<=100000;j++){
			dp[i+1][j%md] += ( dp[i][j] * cb )%inf;
			dp[i+1][j] += (dp[i][j] * cb2)%inf;
		}
		rem -= num;
	}
	ll ans = 0;
	for(int i=0;i<=x;i++){
		ans = (ans + i*dp[v.size()][i])%inf;
	}
	cout<<ans<<endl;
	return 0;
}