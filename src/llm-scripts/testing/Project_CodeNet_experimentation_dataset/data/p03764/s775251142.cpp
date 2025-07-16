#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define ep emplace_back
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}





int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,m;cin >> n >> m;
	vector<ll> x(n), y(m);
	rep(i,n) cin >> x.at(i);
	rep(i,m) cin >> y.at(i);
	ll ans = 0, sum = 0;
	rep(i,n){
		ans += x.at(i) * i - x.at(i) * (n - i - 1);
		ans %= mod;
	}
	rep(i,m){
		sum += y.at(i) * i - y.at(i) * (m - i - 1);
		sum %= mod;
	}
	cout << ans * sum % mod << endl;
}
