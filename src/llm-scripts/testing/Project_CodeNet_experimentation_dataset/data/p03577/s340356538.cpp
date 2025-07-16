#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

int main() {
    cin >> S;

    reverse(S.begin(), S.end());
    string new_S = S.substr(8, S.length()-8);
    reverse(new_S.begin(), new_S.end());

    cout << new_S << endl;

    return 0;
}
