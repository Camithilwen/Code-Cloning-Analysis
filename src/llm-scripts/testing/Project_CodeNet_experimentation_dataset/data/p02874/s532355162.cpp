#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int mx = -INF, mi = INF;
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    rep(i,n){
        cin >> l[i] >> r[i];
        --l[i];
        chmax(mx, l[i]);
        chmin(mi, r[i]);
    }
    int ans = 0;
    rep(i,n) chmax(ans, max(mi - mx, 0) + r[i] - l[i]);
    vector<P> v;
    rep(i,n){
        int a = max(mi - l[i], 0);
        int b = max(r[i] - mx, 0);
        v.emplace_back(b, -a);
    }
    sort(v.begin(), v.end());
    int left = INF;
    rep(i,n){
        if(i > 0) chmax(ans, left + v[i].first);
        chmin(left, -v[i].second);
    }
    cout << ans << endl;
    return 0;
}
