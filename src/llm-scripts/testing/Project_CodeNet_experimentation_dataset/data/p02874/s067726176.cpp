#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	ll n, lbuf, rbuf, mi;
	cin >> n;
	P lr[n];
	ll ans = 0;
	zep(i, 0, n){
		cin >> lbuf >> rbuf;
		lr[i] = P(rbuf, lbuf);
		if(rbuf-lbuf+1 > ans){
			ans = rbuf-lbuf+1;
			mi = i;
		}
	}
	ll lm = 0;
	ll rm = 1e9;
	zep(i, 0, n){
		if(i != mi){
			lm = max(lr[i].second, lm);
			rm = min(lr[i].first, rm);
		}
	}
	ans += max(rm-lm+1, 0LL);
	
	sort(lr, lr+n);
	zep(i, 0, n){
		ll tmp = lr[i].first;
		lr[i].first = lr[i].second;
		lr[i].second = tmp;
	}
	
	ll al[n], dl[n], ar[n], dr[n];
	al[0] = lr[0].first;
	ar[0] = lr[0].second;
	zep(i, 1, n){
		al[i] = max(lr[i].first, al[i-1]);
		ar[i] = min(lr[i].second, ar[i-1]);
	}
	
	dl[n-1] = lr[n-1].first;
	dr[n-1] = lr[n-1].second;
	rrep(i, n-2, 0){
		dl[i] = max(lr[i].first, dl[i+1]);
		dr[i] = min(lr[i].second, dr[i+1]);
	}
	
	zep(i, 0, n-1){
		ans = max(ar[i]-al[i]+1+dr[i+1]-dl[i+1]+1, ans);
	}
	print(ans)
	return 0;
}