#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC return 0;
using namespace std;
string s;
int res;
int main() {
    DAU
    cin >> s;
    s = '0' + s;
    for (int i = (int)s.size() - 1; i > 0; --i) {
        if (s[i] <= '4' || (s[i] == '5' && s[i-1] < '5'))
            res += s[i] - '0';
        else {
            res += '9' + 1 - s[i];
            ++s[i-1];
        }
    }
    res += s[0] - '0';
    cout << res;
    PLEC
}
