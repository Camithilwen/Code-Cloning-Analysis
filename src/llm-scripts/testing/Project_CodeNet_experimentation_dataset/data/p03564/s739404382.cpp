#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    int ans = 1;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        ans = min(ans*2, ans+k);
    }
    cout << ans << endl;
}