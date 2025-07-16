#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n) {
        cin >> p[i];
    }
    vector<int> s(n-k+1,0);
    rep(i,k) s[0] += p[i];
    rep(i,n-k) s[i+1] = s[i] - p[i] + p[i+k];
    int ans = 0;
    rep(i,n-k+1) chmax(ans, s[i]);
    cout << std::fixed << (ans+k)/2.0  << endl;
}
