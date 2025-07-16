#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    string s;
    cin >> s;
    map<char, int> dic;
    rep(i, 26) dic[i + 'a'] = 0;
    int n = s.size();
    rep(i, n) dic[s[i]]++;
    rep(i, 26)
    {
        if (dic['a' + i] < 1)
        {
            cout << char('a' + i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}