#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define INF (1<<30)-1
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  const int MOD = 998244353;
  int n; cin >> n;
  map<int,int> mp;
  vi d(n);
  int mx = 0;
  rep(i,n){
    cin >> d[i];
    mp[d[i]]++;
    chmax(mx,d[i]);
  }
  if(mp[0]!=1 || d[0]!=0){
    cout << 0;
    return 0;
  }
  ll ans = 1;
  for(int i = 1; i <= mx; i++){
    // ll res = (ll)pow(mp[i-1],mp[i]);
    ll res = 1;
    rep(j,mp[i]){
      res *= mp[i-1];
      res %= MOD;
    }
    ans *= res;
    ans %= MOD;
  }
  cout << ans;
  cout << "\n";
  return 0;
}
