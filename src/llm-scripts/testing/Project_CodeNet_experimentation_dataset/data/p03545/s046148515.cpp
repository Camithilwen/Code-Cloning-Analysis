#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    rep(bit, 1 << 3)
    {
        int tmp = s[0] - '0';
        string ans;
        ans += s[0];
        rep(i, 3)
        {
            if (bit & (1 << i))
            {
                tmp += s[i + 1] - '0';
                ans += "+";
                ans += s[i + 1];
            }
            else
            {
                tmp -= s[i + 1] - '0';
                ans += "-";
                ans += s[i + 1];
            }
        }
        if (tmp == 7)
        {
            printf("%s=7\n", ans.c_str());
            return;
        }
    }
}

int main()
{
    solve();
    return 0;
}