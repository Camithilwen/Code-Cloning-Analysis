#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Pxy = pair<double, double>;
using T = tuple<int, int, bool>;
const int INF = 1001001007;
const int mod = 1000000007;
const int MOD = 998244353;
const ll inf = 1e18;
template <typename AT>
void printvec(vector<AT> &ar){
    rep(i,ar.size()-1) cout << ar[i] << " ";
    cout << ar[ar.size()-1] << endl;
}
template <typename Q>
void printvvec(vector<vector<Q>> &ar){
    rep(i,ar.size()){
        rep(j,ar[0].size()-1) cout << ar[i][j] << " ";
        cout << ar[i][ar[0].size()-1] << endl;
    }
}
template <typename S>
bool range(S a, S b, S x){
    return (a <= x && x < b);
}

void yes(int n){
    cout << "Yes" << endl;
}

void no (int n){
    cout << "No" << endl;
}

int main() {
    ll n, x; cin >> n >> x;
    vector<ll> ar(n);
    rep(i,n) cin >> ar[i];
    ll ans = 0;
    rep(i,n){
        ans += max(0LL,ar[i] - x);
        ar[i] = min(ar[i],x);
    }
    rep(i,n-1){
        ans += max(0LL,-x + ar[i] + ar[i+1]);
        ar[i+1] = min(ar[i+1],x - ar[i]);
    }
    cout << ans << endl;
}