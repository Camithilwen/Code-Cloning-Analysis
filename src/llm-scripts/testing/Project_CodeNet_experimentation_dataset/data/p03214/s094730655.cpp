#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = (int)1e9 + 7;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (auto &ai: a) cin >> ai, sum += ai;
    pair<int, int> mi{INF, -1};
    for (int i = 0; i < n; i++) {
        mi = min(mi, {abs(a[i] * n - sum), i});
    }
    cout << mi.second << endl;
    return 0;
}
