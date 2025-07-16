#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int k;
    vector<int> ab{0, 0};
    cin >> ab[0] >> ab[1] >> k;

    int i = 0;
    while (k--) {
        if (ab[i] & 1) {
            ab[i]--;
        }
        ab[i] >>= 1;
        ab[i ^ 1] += ab[i];
        i ^= 1;
    }
    cout << ab[0] << " " << ab[1] << endl;
}