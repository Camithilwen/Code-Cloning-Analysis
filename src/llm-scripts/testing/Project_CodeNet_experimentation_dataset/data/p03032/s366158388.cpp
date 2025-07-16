#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

vector<vector<vector<ll>>> dp(51, vector<vector<ll>>(51, vector<ll>(101, 0)));

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> V(N);
    rep(i, N) cin >> V.at(i);
    ll ans = 0;
    rep(l, min(N, K)+1){
        rep(r, min(N, K)+1){
            rep(d, l+r+1){
                if(l+r+d > K){
                    continue;
                }
                if(l+r > N){
                    continue;
                }
                vector<ll> get(0);
                rep(i, l){
                    get.push_back(V.at(i));
                }
                rep(i, r){
                    get.push_back(V.at(N-1-i));
                }
                sort(all(get));
                get.erase(get.begin(), get.begin()+d);
                ll tmp = 0;
                rep(i, sz(get)){
                    tmp += get.at(i);
                }
                chmax(ans, tmp);
            }
        }
    }
    cout << ans << endl;
}