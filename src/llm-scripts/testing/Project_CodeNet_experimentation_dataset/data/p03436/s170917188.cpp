#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    int white_cnt = 0;
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
        for (int j = 0; j < w; j++)
        {
            if(s[i][j] == '.')white_cnt++;
        }
    }

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    vector<vector<int>> seen(h, vector<int>(w, -1));
    queue<pair<int, int>> que;

    seen[0][0] = 0;
    que.push(make_pair(0, 0));

    while (!que.empty())
    {
        pair<int ,int> pos = que.front();
        int x = pos.first, y = pos.second;
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            
            if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
            if(s[nx][ny] == '#')continue;

            if(seen[nx][ny] == -1)
            {
                que.push(make_pair(nx, ny));
                seen[nx][ny] = seen[x][y] + 1;
            }
        }
    }

    if(seen[h - 1][w - 1] == -1)cout << -1 << endl;
    else cout << white_cnt - seen[h - 1][w - 1] - 1 << endl;
}