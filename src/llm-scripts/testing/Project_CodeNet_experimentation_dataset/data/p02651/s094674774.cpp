// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
#define endl '\n'
#define ld long double
#define all(a) a.begin(),a.end()
#define int long long
#define pb push_back
#define pii pair <int, int>
#define ff first
#define ss second
#define sz(v) (int)v.size() 
#define UB upper_bound
#define LB lower_bound
#define BP(x) __builtin_popcountll(x)
#define OST tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}

const int INF = 1e18 + 0;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const int MAXLOG = 62;

struct basis {
  int base[MAXLOG];

  void clear() {
   for(int i = MAXLOG - 1; i >= 0; i--) base[i] = 0;
  }
  void prepare(int val) {
    for(int i = MAXLOG - 1; i >= 0; i--) {
      if((val >> i) & 1) {
      if(!base[i]) { base[i] = val; return; }
      else val ^= base[i];
    }
  } 
 }  
 int size() {
   int c = 0;
   for(int i = 0; i < MAXLOG; i++) c += (bool)(base[i]);
   return c;
 }
 int max_xor() {
  int res = 0;
  for(int i = MAXLOG - 1; i >= 0; i--)
    if(!((res >> i) & 1) && base[i]) res ^= base[i];
  return res;
 }
 bool possible(int val) {
   for(int i = MAXLOG - 1; i >= 0; i--)
     if(((val >> i) & 1) && base[i]) val ^= base[i];
   return (val == 0);
  }
};

void solve() {
  int n; cin >> n;
  int data[n+5];
  for(int i = 0; i < n; i++) cin >> data[i];
  basis b; b.clear();
  string s; cin >> s;
  for(int i = n-1; i >= 0; i--) {
     if(s[i] == '1') {
       if(!b.possible(data[i])) {
        cout << "1\n"; return;
       }
     } else {
      b.prepare(data[i]);
     }
  }
  cout << "0\n";
}

signed main() {   
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif
   int t = 1;  cin >> t;
   for(int i = 1; i <= t; i++) {
     solve();
  }
}    
