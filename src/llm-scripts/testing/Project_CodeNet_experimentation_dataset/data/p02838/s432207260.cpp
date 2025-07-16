#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0)
typedef long long ll;
#define int ll
#define swap(x, y)((x)^=(y)^=(x)^=(y))
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> matrix;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(c) c.begin(),c.end()
#define mp make_pair
#define pb push_back
#define f first
#define tcase int _; cin>> _; for( ; _; --_)
#define s second
#define endl '\n'
const int MAX = 1e6+1;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const double DEG = 180/PI;
const int MOD = 1e9+7;
int mod(int x, int m){ if(x >= 0) return x % m; if(-x < m) return m-(-x); return mod(x%m, m);}
int gcd (int a, int b) {while(b){a = mod(a, b); swap(a, b);} return a;}
int lcm (int a, int b) {return a / gcd(a, b) * b;}
int fexp(int base, int exp, int m){
	int total = 1;
	while(exp > 0){
		if(exp % 2 == 1){
			total = mod(((mod(total, m)) * (mod(base, m))), m);
			exp--;
		}
		base= mod((mod(base, m) * mod(base, m)), m);
		exp /= 2;
	}
	return mod(total, m);
}

int n;

void solve(){
	cin>> n;

	vector<ll> cnt(60, 0);

	for(int i = 0; i<n; ++i){
		ll x;
		cin>> x;

		for(int j = 1, k = 0; j <= x; j<<=1LL, ++k) if(j & x) cnt[k]++;
	}

	ll ans = 0LL;

	for(int i = 0; i<60; ++i){
		ll temp = mod(cnt[i] * (n - cnt[i]), MOD);
		ans = mod(ans + mod(temp * mod(1LL << i, MOD), MOD), MOD);
	}
	cout<< ans << endl;
}

int32_t main(){
	fastio;
	solve();
	return 0;
}
