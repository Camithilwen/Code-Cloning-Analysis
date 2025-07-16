#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long t1, t2, ans, t;
    ans = 0;
    cin >> n >> t;
    cin >> t1;
    t1 = t2 = 0;
    for (int i=1;i<n; ++i) {
        cin >> t1;
        ans += min(t1 - t2, t);
        t2 = t1;
    }
    ans += t;
    cout << ans;

}

int main() {

    solve();
    return 0;
}
