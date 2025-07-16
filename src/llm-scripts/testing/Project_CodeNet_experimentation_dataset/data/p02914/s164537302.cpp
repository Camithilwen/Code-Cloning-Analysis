#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long li;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    li n;
    cin >> n;

    vector<li> xs(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i];
    }

    li xorsum = 0;
    for (int i = 0; i < n; ++i) {
        xorsum ^= xs[i];
    }

    li ans = 0;
    for (unsigned int pos = 0; pos < 60; ++pos) {
        if ((xorsum & (1ULL << pos)) != 0) {
            ans += 1ULL << pos;
            for (int i = 0; i < n; ++i) {
                xs[i] &= ~(1ULL << pos);
            }
        }
    }

    vector<bool> used(n);
    for (unsigned int pos = 59; pos <= 59; --pos) {
        for (int pivot = 0; pivot < n; ++pivot) {
            if ((xs[pivot] & (1ULL << pos)) != 0 && !used[pivot]) {
                used[pivot] = true;
                for (int i = 0; i < n; ++i) {
                    if (i == pivot) {
                        continue;
                    }
                    if ((xs[i] & (1ULL << pos)) == 0) {
                        continue;
                    }
                    xs[i] ^= xs[pivot];
                }
            }
        }
    }

    li dupsum = 0;
    for (int i = 0; i < n; ++i) {
        dupsum ^= xs[i];
    }

    cout << ans + dupsum * 2 << endl;

    return 0;
}