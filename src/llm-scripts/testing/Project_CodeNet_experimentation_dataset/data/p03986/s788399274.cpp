#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s;
    int lc = 0, rc = 0;
    for (auto& i : s) {
        if (i == 'S') lc++;
        else {
            if (lc) lc--;
            else rc++;
        }
    }
    cout << lc + rc;
}

