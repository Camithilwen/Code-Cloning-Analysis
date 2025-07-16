#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    if (s == "SSS") {
        cout << 0 << endl;
        return 0;
    }
    int ans = 1;
    if (s[0] == 'R' && s[1] == 'R') ans++;
    if (s[1] == 'R' && s[2] == 'R') ans++;
    cout << ans << endl;
}
