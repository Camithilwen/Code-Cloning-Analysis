#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    vector<int> a(2 * n);

    for (int i = 0; i < (n << 1); i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < (n << 1); i+=2) {
        ans += a[i];
    }
    cout << ans;    
    
}