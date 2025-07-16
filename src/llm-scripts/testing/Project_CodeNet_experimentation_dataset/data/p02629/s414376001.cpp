#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n;
    cin >> n;
    ll sum = 26;
    ll cnt = 1;
    while (1)
    {
        if (n <= sum)
            break;
        sum = sum * 26 + 26;
        cnt++;
    }
    vector<string> res(cnt);
    rep(i, cnt)
    {
        n--;
        int ans = n % 26;
        res[cnt - i - 1] = (char)('a' + ans);
        n /= 26;
    }
    rep(i, res.size()) cout << res[i];
    cout << endl;
}
