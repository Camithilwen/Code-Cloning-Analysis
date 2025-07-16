#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const ll Mod = 1e9 + 7;
const ll Inf = 2242545357980376863LL;
const ll Log = 20;
const ll N = 1ll << Log;
const int Maxn = 5e2 + 10;
const int Base = 101;

ll c1[30], c2[30];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(c2, 31 , sizeof c2);
	ll n, m;
	cin >> n >> m;
	ll s1 = 0, s2 = 0;
	ll sm = 0, v;
	for(int i = 0; i < n; i++){
		cin >> v;
		s1 += ((v * i) - sm);
		sm += v;
	}
	sm = 0;
	for(int i = 0; i < m; i++){
		cin >> v;
		s2 += ((v * i) - sm);
		sm += v;
	}
	cout << (s1 % Mod)*(s2 % Mod) % Mod;
	return 0;
}
