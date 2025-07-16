#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using vi = vector<int>;
using pii = pair<int, int>;
#define fir first
#define sec second

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    // input
    int d, g;
    cin >> d >> g;
    vector<int> p(d), c(d);
    rep(i, d) {
        cin >> p[i] >> c[i];
    }
    // solve
    int min_c = 1000;
    rep(bit, 1<<d) {
        int cnt = 0, scr = 0;
        rep(i, d) {
            if (bit & 1<<i) {
                scr += 100 * (i+1) * p[i] + c[i];
                cnt += p[i];
            }
        }
        if (scr >= g) chmin(min_c, cnt);
        else {
            repr(i, d) {
                if (~bit & 1<<i) {
                    rep(j, p[i]-1) {
                        scr += 100 * (i+1);
                        cnt++;
                        if (scr >= g) break;
                    }
                }
                if (scr >= g) break;
            }
            if (scr >= g) chmin(min_c, cnt);
        }
    }
    // output
    cout << min_c << endl;
}