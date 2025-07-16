#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s ^= a[i];
    }

    ll r = 0;
    int i0 = 0;
    for (int k = 60 - 1; k >= 0; k--) {
        ll l = 1LL << k;
        if (s & l) continue;
        for (int i = i0; i < n; i++) {
            if (a[i] & l) {
                ll t = a[i];
                for (int j = i + 1; j < n; j++) {
                    if (a[j] & l) {
                        a[j] ^= t;
                    }
                }
                swap(a[i0++], a[i]);
                if (!(r & l)) r ^= t;
                break;
            }
        }
    }

    r &= ~s;
    r *= 2;
    r += s;

    cout << r << endl;

    return 0;
}