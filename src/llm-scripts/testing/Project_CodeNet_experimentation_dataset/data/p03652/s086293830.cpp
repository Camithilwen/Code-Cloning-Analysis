#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) rep(j, m) cin >> a[i][j];

    set<int> excluded;
    int ans = 1e6;
    for (int k = 0; k < m; k++) {
        vector<int> counter(m + 1, 0);
        int toBeExcluded = 0;
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (j < m && excluded.count(a[i][j])) {
                j++;
            }
            counter[a[i][j]]++;
            if (counter[toBeExcluded] < counter[a[i][j]]) {
                toBeExcluded = a[i][j];
            }
        }
        ans = min(ans, counter[toBeExcluded]);
        excluded.insert(toBeExcluded);
    }
    cout << ans << endl;
}