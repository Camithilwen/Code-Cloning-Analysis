#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    vector<char> S(A + B + 1);
    for (int i = 0; i < A + B + 1; i++) {
        cin >> S.at(i);
    }

    string ans = "Yes";
    if (S.at(A) != '-') ans = "No";
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == '-' && i != A) ans = "No";
    }
    cout << ans << endl;
}