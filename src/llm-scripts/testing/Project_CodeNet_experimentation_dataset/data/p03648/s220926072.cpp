#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int n = 50;

int main() {
    ll k;
    cin >> k;
    cout << n << endl;

    vector<ll> ret(n, n - 1);
    for (int i = 0; i < k % n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)ret[j] += n;
            else ret[j]--;
        }
    }
    for (int i = 0; i < n; i++) ret[i] += k / n;

    for (int i = 0; i < n; i++) {
        if (i > 0)cout << " ";
        cout << ret[i];
    }
    cout << endl;
    return 0;
}