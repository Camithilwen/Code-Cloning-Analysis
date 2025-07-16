#include <bits/stdc++.h>
 
//#include <unistd.h>
//#include <iostream>
 
using namespace std;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
//#define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);
const ll MOD = 1000000007;
//const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'
vector<int> knuth_morris_pratt(const vi &s){
  int n=s.size();
  vector<int> kmp(n+1,-1),mp(n+1,-1);
  for(int i=0,j=-1;i<n;i++){
    while(~j&&s[i]!=s[j]) j=kmp[j];
    kmp[i+1]=mp[i+1]=++j;
    if(i+1<n&&s[i+1]==s[j]) kmp[i+1]=kmp[j];
  }
  return mp;
}
// smallest d s.t. s[x] == s[x + d] for all x
vector<int> minimum_period(const vi &s){
  auto mp=knuth_morris_pratt(s);
  for(int i=1;i<(int)mp.size();i++) mp[i]=i-mp[i];
  return mp;
}
// positions for t that match s
vector<int> pattern_match(vi s,vi t){
  int n=s.size(),m=t.size();
  vector<int> kmp=knuth_morris_pratt(s);

  vector<int> res;
  int i=0,j=0;
  while(i+j<m){
    if(s[j]==t[i+j]){
      if(++j!=n) continue;
      res.emplace_back(i);
    }
    i+=j-kmp[j];
    j=max(kmp[j],0);
  }
  return res;
}

signed main() {
  int n;
  cin >> n;
  vi a(n), b(n);
  rep (i, n) cin >> a[i];
  rep (i, n) cin >> b[i];

  vi aa(n);
  vi bb(2 * n - 1);
  rep (i, 2 * n - 1) {
    int j = i % n;
    bb[i] = b[j] ^ b[(j + 1) % n];
    if (i < n) {
      aa[i] = a[j] ^ a[(j + 1) % n];
    }
  }
  DEBUG_VEC(aa);
  DEBUG_VEC(bb);

  vi ans = pattern_match(aa, bb);
  DEBUG_VEC(ans);
  vector<pii> out;
  rrep (i, ans.size()) {
    out.emplace_back((n - ans[i]) % n, a[0] ^ b[ans[i]]);
  }
  sort(all(out));
  rep (i, out.size()) {
    cout << out[i].first << " " << out[i].second << endl;
  }
}