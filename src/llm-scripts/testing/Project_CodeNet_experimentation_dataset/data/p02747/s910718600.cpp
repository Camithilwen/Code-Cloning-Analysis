#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    bool ok = true;
    if (S.size() % 2 == 1) ok = false;
    for (int i = 0; i < S.size() / 2; i += 2) {
        if (S.substr(i, 2) != "hi") {
            ok = false;
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}