#include <bits/stdc++.h>
using namespace std;

int counter(int bits) {
    if (bits == 0) return 0;
    return counter(bits >> 1) + (bits & 1);
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<vector<int> > x(n+1, vector<int>(n+1));
    vector<vector<int> > y(n+1, vector<int>(n+1));
    for (size_t i = 1; i <= n; i++) {
        cin >> a[i];
        for (size_t j = 1; j <= a[i]; j++) {
            cin >> x[i][j] >> y[i][j];
        }
    }

    int ans = 0;
    for (int bits = 1; bits < (1<<n); bits++) {
        bool can = true;
        for (int i = 1; i <= n; i++) {
            if (bits & 1<<(i-1)) {
                for (size_t j = 1; j <= a[i]; j++) {
                    if (((bits >> (x[i][j]-1)) & 1) ^ y[i][j]) can = false;
                }
            }
        }
        if (can) ans = max(ans, counter(bits));
    }

    cout << ans << endl;
    return 0;
}
