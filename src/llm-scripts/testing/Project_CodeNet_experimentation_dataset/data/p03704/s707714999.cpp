#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll d;
map < ll, ll > mp[20];
ll pw10[20];
ll coef[20];
ll gc[20];
int LEN = 0;
int val[25];
int val0[25];
ll solve(int where, ll need) {
    //cout << where << " " << need << endl;
    if (where == LEN) {
        return (need == 0);
    }
    if (gc[where] != 0 && need % gc[where] != 0) return 0;
    //if (need % gc[where] != 0) return 0;
    if (coef[where] == 0) {
        if (need == 0) return 10;
        else return 0;
    }
    if (mp[where].find(need) != mp[where].end()) {
        return mp[where][need];
    }
    ll tot = 0;
    for (int i = -9; i <= 9; i++) {
        if (where) tot += solve(where + 1, need - i * coef[where]) * val[i + 9];
        else {
            tot += solve(where + 1, need - i * coef[where]) * val0[i + 9];
        }
    }
    return mp[where][need] = tot;
}
ll solve(int len) {
    LEN = (len + 1) / 2;
    for (int i = 0; i <= LEN; i++) mp[i].clear();
    for (int i = 0; i < (len + 1) / 2; i++) {
         coef[i] = pw10[len - 1 - i] - pw10[i];
         coef[i] /= 9;
    }
    gc[LEN] = 0;
    for (int i = LEN - 1; i >= 0; i--) gc[i] = __gcd(coef[i], gc[i + 1]);
    return solve(0, d);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            val[i - j + 9]++;
            if (j) val0[i - j + 9]++;
        }
    }
    pw10[0] = 1;
    for (int i = 1; i <= 18; i++) pw10[i] = 10 * pw10[i - 1];
    cin >> d;
    if (d % 9 != 0) {
        cout << 0;
        return 0;
    }
    d /= 9;
    ll f = 0;
    for (int len = 2; len <= 18; len++) {
        f += solve(len);
    }
    cout << f << endl;

    return 0;
}
