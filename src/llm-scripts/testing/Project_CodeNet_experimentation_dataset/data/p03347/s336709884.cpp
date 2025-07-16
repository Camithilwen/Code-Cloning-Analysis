#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0, cnt = 0;
    if(a[0] != 0){
        cout << -1 << endl;
        return 0;
    }
    vector<int> b(n, 0);
    for(int i = n-1; i >= 0; i--){
        if(b[i] > a[i]){
            cout << -1 << endl;
            return 0;
        }
        if(i > 0) b[i-1] = max(0, a[i] - 1);
        if(a[i] == b[i]) continue;
        ans += a[i];
    }
    cout << ans << endl;
	return 0;
}