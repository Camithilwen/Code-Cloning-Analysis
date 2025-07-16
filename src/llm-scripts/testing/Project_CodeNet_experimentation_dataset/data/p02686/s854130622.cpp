#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
  #define debug(x) cerr << #x << ": " << x << endl;
#else
  #define debug(x)
#endif

int main() {
  cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

  ll N;
  cin >> N;

  vpll vl, vr;
  vll xmin(N, 0), xlast(N, 0);
  rep(i,N) {
    string s;
    cin >> s;
    for(auto c : s) {
      if(c =='(') xlast[i]++;
      else xlast[i]--;
      chmin(xmin[i], xlast[i]);
    }
    if(xlast[i] >= 0) vl.emplace_back(-xmin[i], i);
    else vr.emplace_back(xmin[i] - xlast[i], i);
  }

  sort(vl.begin(), vl.end());
  sort(vr.begin(), vr.end());

  ll tmin = 0, tlast = 0;
  for(auto p : vl) {
    ll i = p.second;
    chmin(tmin, tlast + xmin[i]);
    tlast += xlast[i];
  }
  for(auto p : vr) {
    ll i = p.second;
    chmin(tmin, tlast + xmin[i]);
    tlast += xlast[i];
  }

  if(tlast == 0 && tmin == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}