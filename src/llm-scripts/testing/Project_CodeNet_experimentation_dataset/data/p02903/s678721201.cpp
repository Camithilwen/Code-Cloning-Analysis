#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;


int main() {
    Int H, W, A, B;
    cin >> H >> W >> A >> B;

    vector<string> s(H);

    if (B > 0) {
        rep(i,B) {
            if (A > 0) {
                rep(j,A) {
                    s[i] += '1';
                }
            }
            rep(j,W-A) s[i] += '0';
        }
    }
    for (int i = B; i<H; i++) {
        if (A > 0) {
                rep(j,A) {
                    s[i] += '0';
                }
            }
            rep(j,W-A) s[i] += '1';
    }

    rep(i,H) cout << s[i] << endl;
}