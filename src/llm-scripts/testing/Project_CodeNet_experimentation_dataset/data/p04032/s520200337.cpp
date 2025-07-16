#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    string s;
    cin >> s;
    ll n = s.length();

    //2文字条件
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            cout << i + 1 << " " << i + 2 << endl;
            return 0;
        }
    }

    //3文字条件
    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == s[i + 2])
        {
            cout << i + 1 << " " << i + 3 << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;
}
