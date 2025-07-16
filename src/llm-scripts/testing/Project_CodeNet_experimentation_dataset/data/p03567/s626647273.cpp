#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    bool ok = false;
    rep(i, s.size() - 1) {
        if(s[i] == 'A' && s[i + 1] == 'C') ok = true;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
