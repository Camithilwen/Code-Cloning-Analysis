#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s.at(i);
    cin >> m;
    vector<string> t(m);
    rep(i, m) cin >> t.at(i);

    int ans = 0;
    string say;
    rep(i, n) {
        int rwd = 0;
        say = s.at(i);
        rep(i, n) {
            if(say == s.at(i)) rwd++;
        }
        rep(i, m) {
            if(say == t.at(i)) rwd--;
        }
        if(rwd > ans) ans = rwd;
    }
    cout << ans << endl;
}
