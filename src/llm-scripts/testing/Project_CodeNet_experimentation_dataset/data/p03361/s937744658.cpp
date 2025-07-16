#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    string ans = "Yes";
    int h, w;
    cin >> h >> w;
    vector<string> S(h);
    for (int i = 0; i < h; ++i)
    {
        cin >> S[i];
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (S[i][j] == '#')
            {
                bool can = false;
                for (int k = 0; k < 4; ++k)
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni < 0 || ni > h - 1)
                    {
                        continue;
                    }
                    if (nj < 0 || nj > w - 1)
                    {
                        continue;
                    }
                    if (S[ni][nj] == '#')
                    {
                        can = true;
                    }
                }
                if (can == false)
                {
                    ans = "No";
                }
            }
        }
    }
    cout << ans << endl;
}