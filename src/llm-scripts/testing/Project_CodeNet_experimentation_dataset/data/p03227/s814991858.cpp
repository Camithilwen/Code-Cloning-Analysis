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
    if(s.size() == 2) cout << s << endl;
    else {
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}