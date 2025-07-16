#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n,T;
    cin >> n >> T;
    int si = 0;
    int now = 0;
    int ans = 0;
    bool ok = false;
    rep(i,n) {
        int t;
        cin >> t;
        if(i==0) {
            now += T;
            continue;
        }
        if(now>=t) now = t+T;
        else {
            ans += now - si;
            si = t;
            now = t+T;
        }
    }
    ans += now-si;
    cout << ans << endl;
}