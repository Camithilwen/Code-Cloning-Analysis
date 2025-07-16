#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool chk(int bit, vector<vector<P>> &p)
{
    bool result = true;

    for (int i = 0; i < (int)p.size(); i++)
    {
        if (!(bit & (1 << i)))
        {
            continue;
        }

        for (int j = 0; j < (int)p[i].size(); j++)
        {
            int tx = p[i][j].first;
            int ty = p[i][j].second;

            if ((ty == 1 && (bit & (1 << tx))) ||
                (ty == 0 && (~bit & (1 << tx))))
            {
                continue;
            }
            else
            {
                result = false;
            }
        }
    }

    return result;
}

int main()
{
    int n;
    int a;
    vector<vector<P>> p;
    int cnt = 0, ans = 0;

    // 入力
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        p[i].resize(a);
        for (int j = 0; j < a; j++)
        {
            cin >> p[i][j].first >> p[i][j].second;
            --p[i][j].first;
        }
    }

    // 処理
    for (int bit = 0; bit < (1 << n); bit++)
    {
        if (chk(bit, p))
        {
            cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (bit & (1 << i))
                    cnt++;
            }
            ans = max(ans, cnt);
        }
    }

    // 出力
    cout << ans << endl;

    return 0;
}
