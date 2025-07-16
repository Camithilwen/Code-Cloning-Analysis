#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    ll k, a[55] = {};
    cin >> k;
    for (int i = 0; i < 50; i++) a[i] = k / 50 + 50 - 1;
    for (int i = 0; i < k % 50; i++) {
        for (int j = 0; j < 50; j++) a[j]--;
        a[i] += 51;
    }
    cout << 50 << '\n';
    for (int i = 0; i < 50; i++) cout << a[i] << ' ';
}
