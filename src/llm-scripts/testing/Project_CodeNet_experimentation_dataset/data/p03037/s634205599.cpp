#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    double n, m;
    cin >> n >> m;
    vector<int> L(m), R(m);
    rep(i, m) cin >> L[i] >> R[i];
    int maxi = *max_element(L.begin(), L.end());
    int mini = *min_element(R.begin(), R.end());
    if(mini < maxi) {
        cout << 0 << endl;
    } else {
        cout << mini - maxi + 1 << endl;
    }
    return 0;
}