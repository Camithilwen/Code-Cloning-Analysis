#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 10000000;

int main() {
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i-1] == s[i])  {
            cout << i << " " << i+1 << endl;
            return 0;
        }
    }
    for (int i = 0; i+2 < s.size(); i++) {
        if (s[i] == s[i+2]) {
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
}
