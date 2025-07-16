#include "bits/stdc++.h"

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int k = s.size();
    while (s[k - 1] != 'F')
        k--;
    cout << s.substr(0, k - 1) << endl;
}

int main()
{
    solve();
    return 0;
}
