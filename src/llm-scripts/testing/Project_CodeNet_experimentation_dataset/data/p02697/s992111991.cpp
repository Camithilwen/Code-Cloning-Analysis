#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define getbit(n, i) (((n) & (1LL << (i))) != 0)
#define setbit0(n, i) ((n) & (~(1LL << (i))))
#define setbit1(n, i) ((n) | (1LL << (i)))
#define togglebit(n, i) ((n) ^ (1LL << (i)))
char gap = 32;
template < typename T >
ostream& operator<<(ostream &os, const vector < T > &v) {
  os << '{';
  for (const auto &x: v) os << gap << x;
  return os << '}';
}
template < typename A, typename B >
ostream& operator<<(ostream &os, const pair < A, B > &p) {
  return os << '(' << p.first << gap << p.second << ')';
}

template < class T >
void read(T &x) {
  char c;
  for (c = getchar(); c < '0' || c > '9'; c = getchar());
  for (x = 0; c <= '9' && c >= '0'; c = getchar()) x = x * 10 + (c & 15);
}
#define ll long long
#define lll __int128_t
#define pb push_back
#define mp make_pair
typedef pair < int, int > ii;
typedef vector < ii > vii;
typedef vector < ll > vl;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef tree <
int,
null_type,
less < int >,
rb_tree_tag,
tree_order_statistics_node_update >
ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;
ll dp[1001][1001];
ll mod=1000000007;
vector<string>Data;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll i,j,k,l,n,m;
  cin>>n>>m;
  vector<pair<ll,ll>>res;
  ll ini=1;
  ll fina=n;
  vector<ll>used(n+1,0);
  ll kola1=(m+1)/2;
  while(kola1--){
    used[ini]=1;used[fina]=1;
    res.pb({ini++,fina--});
  }
  m=m/2;
  ll cnt=2*m;
  while(m--){
    while(used[ini]==1) ini++;
    res.pb(make_pair(ini,ini+cnt));
    used[ini]=1;
    used[ini+cnt]=1;
    cnt-=2;
  }
  for(auto x:res) cout<<x.first<<" "<<x.second<<'\n';
}