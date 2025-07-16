#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    string s;
    cin >> a >> b >> s;

    string ans = "Yes";
    if (s.at(a) != '-') {
        ans = "No";
    }
    for (int i = 0; i < a+b+1; i++) {
        if (i == a) continue;
        if (s.at(i) == '-') ans = "No";
    }

    cout << ans << endl;

    return 0;
}
