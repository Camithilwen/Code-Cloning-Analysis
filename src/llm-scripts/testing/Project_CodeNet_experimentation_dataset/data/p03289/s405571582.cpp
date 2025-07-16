#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    bool ok = true;
    if (s[0] != 'A')
        ok = false;
    int cnt = 0;
    for (int i = 2; i <= s.size() - 2; i++)
    {
        if (s[i] == 'C')
            cnt++;
    }
    if (cnt >= 2 || cnt == 0)
        ok = false;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == 'C')
            continue;
        if ('A' <= s[i] && s[i] <= 'Z')
            ok = false;
    }
    if (ok)
        cout << "AC" << endl;
    else
        cout << "WA" << endl;
    return 0;
}