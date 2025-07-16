#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()

const int N = 200200;
const int MAXN = 600600;

int ans = 59408656;
int n;

vector<int> on0[MAXN][4];
vector<int> on1[MAXN][4];
vector<int> on2[MAXN][4];
vector<int> on3[MAXN][4];

int Upd(vector<int> a, vector<int> b)
{
    int ans = 59408656;
    int j = 0;
    for (int i = 0; i < a.size(); i++)
    {
        while (j < b.size() && a[i] > b[j]) j++;
        if (j < b.size())
        {
            ans = min(ans, b[j] - a[i]);
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        char dir;
        cin >> x >> y >> dir;
        x += N;
        int z;
        if (dir == 'U') z = 0;
        if (dir == 'R') z = 1;
        if (dir == 'D') z = 2;
        if (dir == 'L') z = 3;
        on0[x][z].push_back(y);
        on1[y][z].push_back(x);
        on2[x + y][z].push_back(x);
        on3[x - y][z].push_back(x);
    }
    for (int i = 0; i < MAXN; i++)
    {
        for (int z = 0; z < 4; z++)
        {
            sort(all(on0[i][z]));
            sort(all(on1[i][z]));
            sort(all(on2[i][z]));
            sort(all(on3[i][z]));
        }
        ans = min(ans, Upd(on0[i][0], on0[i][2]));
        ans = min(ans, Upd(on1[i][1], on1[i][3]));
        ans = min(ans, 2 * Upd(on3[i][0], on3[i][3]));
        ans = min(ans, 2 * Upd(on3[i][1], on3[i][2]));
        ans = min(ans, 2 * Upd(on2[i][1], on2[i][0]));
        ans = min(ans, 2 * Upd(on2[i][2], on2[i][3]));
    }
    if (ans == 59408656) cout << "SAFE";
    else cout << ans * 5;
}
