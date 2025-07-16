#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int res = 0;
    if (s[0] == 'R'||s[1] == 'R'||s[2] == 'R') res = 1;
    if (s[0] == 'R' && s[1] == 'R') res = 2;
    if (s[1] == 'R' && s[2] == 'R') res = 2;
    if (s[0] == 'R' && s[1] == 'R' && s[2] == 'R') res = 3;
    cout << res << endl;
    return 0;
}