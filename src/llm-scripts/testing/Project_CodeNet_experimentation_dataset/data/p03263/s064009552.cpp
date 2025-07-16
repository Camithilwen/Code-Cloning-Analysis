#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int h, w;
    cin >> h >> w;
    int a[h][w];
    rep(i, h)
    {
        rep(j, w) cin >> a[i][j];
    }

    int cnt = 0;
    vector<tuple<int, int, int, int>> ans;
    //現在位置を示す値
    int i = 0, j = 0;
    while (1)
    {
        if (i % 2 == 0)
        {
            if (j == w - 1)
            {
                if (i == h - 1)
                    goto end;
                if (a[i][j] % 2 == 1)
                {
                    cnt++;
                    ans.emplace_back(i + 1, j + 1, i + 2, j + 1);
                    a[i + 1][j]++;
                }
                i++;
            }
            else
            {
                if (a[i][j] % 2 == 1)
                {
                    cnt++;
                    ans.emplace_back(i + 1, j + 1, i + 1, j + 2);
                    a[i][j + 1]++;
                }
                j++;
            }
        }
        if (i % 2 == 1)
        {
            if (j == 0)
            {
                if (i == h - 1)
                    goto end;
                if (a[i][j] % 2 == 1)
                {
                    cnt++;
                    ans.emplace_back(i + 1, j + 1, i + 2, j + 1);
                    a[i + 1][j]++;
                }
                i++;
            }
            else
            {
                if (a[i][j] % 2 == 1)
                {
                    cnt++;
                    ans.emplace_back(i + 1, j + 1, i + 1, j);
                    a[i][j - 1]++;
                }
                j--;
            }
        }
    }
end:
    cout << cnt << endl;
    rep(i, cnt)
    {
        cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << " " << get<3>(ans[i]) << endl;
    }
}