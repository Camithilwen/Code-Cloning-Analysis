#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int k; cin >> k;
    string s; cin >> s;
    string ans;
    if (s.size() <= k) ans = s;
    else {
        ans = s.substr(0, k);
        ans += "...";
    }
    cout << ans << endl;
    return 0;
}