#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int MSB1(long long x) { int d = 0; while ((1LL << d) <= x) d++; return d; }

int main() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (auto &ai: a) cin >> ai, cnt[ai]++;
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int val: a) if (cnt[val]) {
        cnt[val]--;
        int rem = (1 << MSB1(val)) - val;
        if (cnt[rem]) ans++, cnt[rem]--;
    }
    cout << ans << endl;
    return 0;
}
