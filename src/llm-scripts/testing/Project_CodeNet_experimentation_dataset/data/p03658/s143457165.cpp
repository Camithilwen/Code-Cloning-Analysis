#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int l[n];
    for (int i=0; i<n; ++i)
        cin >> l[i];
    sort(l, l+n);
    int ans = 0;
    for (int i=0; i<k; ++i)
        ans += l[n-1-i];
    cout << ans;

}

int main() {

	solve();
    return 0;
}
