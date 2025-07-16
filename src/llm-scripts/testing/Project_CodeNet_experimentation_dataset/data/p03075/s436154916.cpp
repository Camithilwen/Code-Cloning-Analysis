#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int a, b, c, d, e, k;
    vector<int>at(5);
    rep(i, 5)cin >> at[i];
    cin >> k;
    bool ans = true;
    rep(i, 4)for (int j = i + 1; j < 5; j++)if (abs(at[i] - at[j]) > k)ans = false;
    if (ans) {
        cout << "Yay!" << endl;
    }
    else {
        cout << ":(" << endl;
    }
    return 0;
}