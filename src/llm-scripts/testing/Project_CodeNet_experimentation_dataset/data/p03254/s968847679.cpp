// う　し　た　ぷ　に　き　あ　く　ん　笑
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    const int sum_a = accumulate(a.begin(), a.end(), 0LL);
    if (x == sum_a) {
        cout << n << endl;
    } else if (x > sum_a) {
        cout << n - 1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (x >= a[i]) {
                x -= a[i];
            } else {
                cout << i << endl;
                break;
            }
        }
    }
}

// aが小さい子からちょうどお菓子を配るのが最適
