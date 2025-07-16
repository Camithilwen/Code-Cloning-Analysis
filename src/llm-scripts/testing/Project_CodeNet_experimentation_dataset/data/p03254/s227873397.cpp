#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    int n, x;
    cin >> n >> x;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    int index = 0;
    while (x > 0 && index < n) {
        if (x >= a[index]) {
            ans++;
            x -= a[index];
            if (index == n - 1 && x > 0) {
                ans--;
                x = 0;
            }
        }
        index++;
    }
    cout << ans;
}