#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    int cur = 0;
    while (cur < S.size()) {
        if (cur + 1 < S.size() && S[cur] == 'h' && S[cur + 1] == 'i') {
            cur += 2;
        } else {
            break;
        }
    }
    if (cur < S.size()) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}