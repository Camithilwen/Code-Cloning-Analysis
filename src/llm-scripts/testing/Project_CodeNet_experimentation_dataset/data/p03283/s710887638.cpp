#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> S(n, vector<int>(n));
    rep(i, m){
        int l, r; cin >> l >> r; l--, r--;
        S[l][r]++;
    }
    rep(i, n){
        rep(j, n-1){
            S[i][j+1] += S[i][j];
        }
    }
    rep(j, n){
        for(int i=n-1; i>0; i--){
            S[i-1][j] += S[i][j];
        }
    }

    vector<int> res(q);
    rep(i, q){
        int p, q; cin >> p >> q; p--, q--;
        res[i] = S[p][q]; 
    }
    for(auto r: res) cout << r << ln;
}
