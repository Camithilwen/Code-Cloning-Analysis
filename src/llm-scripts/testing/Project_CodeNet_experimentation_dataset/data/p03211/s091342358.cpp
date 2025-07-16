#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    string S; cin >> S;
    int ans = 10000;
    rep(s, S.size() - 2) {
        string T = S.substr(s, 3);
        int x = 0;
        rep(i, 3) x = x * 10 + (T[i] - '0');
        ans = min(ans, abs(753 - x));
    }
    cout << ans << endl;
    return 0;
}