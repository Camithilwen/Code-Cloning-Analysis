#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int a[5], k;
    rep(i, 5) cin >> a[i];
    cin >> k;

    bool ok = true;

    rep(i, 5) {
        for (int j = i+1; j < 5; j++) {
            if (abs(a[i]-a[j]) > k) ok = false;
        }
    }

    if (ok) cout << "Yay!" << endl;
    else cout << ":(" << endl;
}