#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int x, y;
    cin >> x >> y;

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, -1, 0, 1};

    vector<string> board(x);
    rep(i, x) cin >> board[i];

    rep(i, x)
    {
        rep(j, y)
        {
            if (board[i][j] == '#')
            {
                int cnt = 0;
                rep(k, 4)
                {
                    int xx = i + dx[k];
                    int yy = j + dy[k];

                    if (0 <= xx && xx < x && 0 <= yy && yy < y && board[xx][yy] == '#')
                    {
                        cnt++;
                    }
                }
                if (!cnt)
                {
                    cout << "No" << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << '\n';
    return 0;
}
