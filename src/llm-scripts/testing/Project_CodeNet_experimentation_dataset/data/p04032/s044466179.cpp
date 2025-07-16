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

    string s; cin >> s;

    // 長さ2ならXXのみ
    if(s.size() == 2) {
        if(s[0] == s[1]) cout << 1 << " " << 2 << endl;
        else cout << -1 << " " << -1 << endl;
        return 0;
    }

    // XXがあったら出力して終了
    rep(i, s.size()-1) {
        if(s[i] == s[i+1]) {
            cout << i+1 << " " << i+2 << endl;
            return 0;
        }
    }
    
    // XYXがあったら出力して終了
    rep(i, s.size()-2) {
        if(s[i] == s[i+2]) {
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }

    // どれもなければ-1
    cout << -1 << " " << -1 << endl;
}
