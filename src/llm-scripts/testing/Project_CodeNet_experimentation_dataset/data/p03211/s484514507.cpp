#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int d = INT_MAX;
    for (int i = 0, n = s.length() - 3; i <= n; i++) 
        d = min(d, abs(atoi(s.substr(i, 3).c_str()) - 753));

    cout << d << endl;
}