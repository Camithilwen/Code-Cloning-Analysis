#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    if (stoi(s) < 111)
        cout << "111" << endl;
    else if (s[0] == s[1] && s[1] == s[2])
        cout << s << endl;
    else
    {
        int x = s[0] - '0';
        x = 100 * x + 10 * x + x;
        if (x > stoi(s))
            cout << x << endl;
        else
            cout << x + 111 << endl;
    }
}
