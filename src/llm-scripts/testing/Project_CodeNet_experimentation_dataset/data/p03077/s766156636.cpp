#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long n;
    cin >> n;
    long long mn = 1e15 + 1;
    long long pos = 0;
    for (int i = 0; i < 5; i++) {
        long long x;
        cin >> x;
        if (mn > x) {
            pos = i;
            mn = x;
        }
    }
    cout << (n % mn > 0) + (n / mn) + (4ll - pos) + pos;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
