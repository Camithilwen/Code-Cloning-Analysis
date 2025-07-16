#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int accum[N], bulbs[N], n, k;
int main() {
    cin >> n >> k;
    k = min(41, k);
    for (int i = 1; i <= n; ++i) cin >> bulbs[i];
    while (k--) {
        memset(accum, 0, sizeof accum);
        for (int i = 1; i <= n; ++i) {
            int l = max(1, i - bulbs[i]);
            int r = min(n, i + bulbs[i]);
            accum[l]++;
            accum[r + 1]--;
        }
        for (int i = 1; i <= n; ++i) {
            accum[i] += accum[i - 1];
        }
        memcpy(bulbs, accum, sizeof accum);
    }
    for (int i = 1; i <= n; ++i) {
        cout << bulbs[i] << " ";
    }
    return 0;
}


