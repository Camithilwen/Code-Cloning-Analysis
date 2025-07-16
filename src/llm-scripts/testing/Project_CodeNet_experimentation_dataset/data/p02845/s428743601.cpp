#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n; cin >> n;
    vector<int> memo{0, 0, 0};
    ll res = 1;
    rep(i, n){
        int a; cin >> a;
        int cnt = 0;
        rep(i, 3)if(memo[i] == a) cnt++;
        if(cnt == 0){res = 0; break;}
        res = res * cnt % MOD;
        rep(i, 3)if(memo[i] == a){memo[i]++; break;}
    }
    cout << res << ln; 
}
