#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200005;
 
ll n, k;
array<ll, N> old, nw;
bitset<N> used;
 
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& i : a) cin >> i;
    
    for (int i = 0; i < n; ++i) {
        old[max(0ll, i - a[i])]++;
        old[min(n, i + a[i] + 1)]--;
    }
    
    for (int i = 1; i < k; ++i) {
        ll psum = 0;
        used.reset();
        for (int j = 0; j < n; ++j) {
            if (i % 2) {
                psum += old[j];
                // cout << i << ' ' << j << ' ' << psum << '\n';
                ll mn = max(0ll, j - psum), mx = min(n, j + psum + 1);
                if (!used[j]) {
                    used[j] = 1;
                    nw[j] = 0;
                }
                if (!used[mn]) {
                    used[mn] = 1;
                    nw[mn] = 0;
                }
                if (!used[mx]) {
                    used[mx] = 1;
                    nw[mx] = 0;
                }
 
                // cout << j << ' ' << mn << ' ' << mx << '\n';
                nw[mn]++;
                nw[mx]--;
            } else {
                psum += nw[j];
                // cout << i << ' ' << j << ' ' << psum << '\n';
                ll mn = max(0ll, j - psum), mx = min(n, j + psum + 1);
                if (!used[j]) {
                    used[j] = 1;
                    old[j] = 0;
                }
                if (!used[mn]) {
                    used[mn] = 1;
                    old[mn] = 0;
                }
                if (!used[mx]) {
                    used[mx] = 1;
                    old[mx] = 0;
                }
 
                // cout << j << ' ' << mn << ' ' << mx << '\n';
                // cout << old[mn] << ' ' << old[mx] << '\n';
                old[mn]++;
                old[mx]--;
            }
        }

        if (nw == old) break;
    }
 
    if (k % 2) {
        ll psum = 0;
        for (int i = 0; i < n; ++i) {
            psum += old[i];
            cout << psum << ' ';
        }
    } else {
        ll psum = 0;
        for (int i = 0; i < n; ++i) {
            psum += nw[i];
            cout << psum << ' ';
        }
    }
}
