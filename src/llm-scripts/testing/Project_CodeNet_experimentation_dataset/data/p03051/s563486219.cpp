#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;
#define int long long
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define sz(x) (int)x.size()
const int mod = 1e9 + 7;
const int mod1 = 998244353;
typedef long double f80;

#ifndef LOCAL
#pragma GCC optimize ("O2")
#define endl '\n'
#endif

template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

ll pwr(ll a,ll b, ll mod){
    a %= mod;
    int ans = 1;
    while(b){
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 5e5 + 5;
int a[N], pre[N];
int dp[N];
map<int,int> m, m1;
void solve(){
	int n;
	cin >> n;
	fr(i, 1, n){
		cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
	}
	int ans = 0;
	if(pre[n] != 0){ // xor != 0 and odd partitions ...
		int s0 = 1, s1 = 0;
		int val = pre[n];
		fr(i, 1, n){
			if(pre[i] == val){
				dp[i] = s0;
				s1 += dp[i];
				s1 %= mod;
			}
			else if(pre[i] == 0){
				dp[i] = s1;
				s0 += dp[i];
				s0 %= mod;
			}
		}
		cout << dp[n] << endl;
		return;
	}
	// xor = 0
	int c = 0;
	fr(i, 1, n - 1){
		if(pre[i] == 0)
			c++;
	}
	ans = pwr(2, c, mod);
	// xor != 0
	int c0 = 1;
	m[0] = 1;
	dp[0] = 1;
	fr(i, 1, n){
		if(pre[i] == 0){
			c0++;
		}
		else{
			dp[i] = (m1[pre[i]] * c0 - m[pre[i]] + mod + 1) % mod;
			ans += dp[i];
			ans %= mod;
			m[pre[i]] += c0 * dp[i];
			m[pre[i]] %= mod;
			m1[pre[i]] += dp[i];
			m1[pre[i]] %= mod;
		}
	}
	cout << ans;
}
signed main(){
    IO;
    #ifdef LOCAL
        freopen("inp.txt","r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    fr(tt, 1, t){
        solve();
    }
    return 0;
}