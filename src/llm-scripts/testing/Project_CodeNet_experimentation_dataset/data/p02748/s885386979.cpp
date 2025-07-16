#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const int INF = 2e9;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  ll A, B, m;
  cin >> A >> B >> m;
  vl a(A);
  vl b(B);
  ll minia = INF;
  ll minib = INF;
  rep(i, A){
    cin >> a[i];
    chmin(minia, a[i]);
  }
  rep(i,B){
    cin >> b[i];
    chmin(minib, b[i]);
  }
  ll ans = minia + minib;
  rep(i, m){
    ll x, y, c;
    cin >> x >> y >> c;
    ll tmp = a[x - 1] + b[y - 1] - c;
    chmin(ans, tmp);
  }
  print(ans);
}