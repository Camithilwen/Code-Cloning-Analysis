#include <bits/stdc++.h>

using namespace std;
using ll=long long ;

void solve() {
    ll k; cin >> k;
    ll x = k/50;
    int j = k%50;

    vector<ll> a(50, 50+x);
    j = (50-j);
    for (int i = 0; i < j; i++) {
        a[i] += -50+j-1;
    }
    for (int i = j; i < 50; i++) {
        a[i] += j;
    }

    cout << "50\n";
    for (auto& x: a) {
        cout << x << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cout << endl;
}
