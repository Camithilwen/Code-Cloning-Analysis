#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int l, r;
    cin >> l >> r;
    int mod_min = 2019;
    for (int i = l; i <= min(l + 2019, r); i++) {
        for (int j = i + 1; j <= min(l + 2019, r); j++) {
            mod_min = min(mod_min, ((i % 2019) * (j % 2019)) % 2019);
        }
    }
    cout << mod_min << endl;
    return 0;
}