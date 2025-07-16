#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> pref(n, 0), suff(n, 0);

    for (int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + (s[i-1] == 'W');
    }
    for (int i = n-2; i >= 0; i--) {
        suff[i] = suff[i+1] + (s[i+1] == 'E');
    }

    int ans = 1e8;
    for (int i = 0; i < n; i++) {
        ans = min(ans, pref[i] + suff[i]);
    }

    cout << ans << endl;
}