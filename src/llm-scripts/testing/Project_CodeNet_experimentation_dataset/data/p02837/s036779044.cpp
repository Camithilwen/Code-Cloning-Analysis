/*
 * @Author: hesorchen
 * @Date: 2020-07-03 17:05:01
 * @LastEditTime: 2020-09-04 20:28:08
 * @Description: https://hesorchen.github.io/
 */
#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <vector>
#include <bitset>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define PI acos(-1)
#define PB push_back
#define ll long long
#define INF 0x3f3f3f3f
#define mod 1000000007
#define pll pair<ll, ll>
#define lowbit(abcd) (abcd & (-abcd))
#define max(a, b) ((a > b) ? (a) : (b))
#define min(a, b) ((a < b) ? (a) : (b))

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define FRE                              \
    {                                    \
        freopen("in.txt", "r", stdin);   \
        freopen("out.txt", "w", stdout); \
    }

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
//head==============================================================================

struct node
{
    int p, y;
};
vector<node> vec[20];
int a[20];
int all[35000][20];
int vis[20];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                all[i][j + 1] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        for (int j = 1; j <= a[i]; j++)
        {
            int temp1, temp2;
            scanf("%d %d", &temp1, &temp2);
            vec[i].push_back(node{temp1, temp2});
        }
    }
    int ans = 0;

    for (int i = 0; i < (1 << n); i++)
    {
        int flag = 1;
        fill(vis, vis + 18, -1);

        for (int j = 1; j <= n; j++)
        {
            if (!all[i][j])
                continue;
            else
            {
                for (int k = 0; k < a[j]; k++)
                {
                    if (vec[j][k].y != vis[vec[j][k].p] && vis[vec[j][k].p] != -1)
                    {
                        flag = 0;
                        break;
                    }
                    if (vec[j][k].y && !all[i][vec[j][k].p])
                    {
                        flag = 0;
                        break;
                    }
                    if (!vec[j][k].y && all[i][vec[j][k].p])
                    {
                        flag = 0;
                        break;
                    }
                    if (vec[j][k].y)
                        vis[vec[j][k].p] = 1;
                    else
                        vis[vec[j][k].p] = 0;
                }
            }
            if (!flag)
                break;
        }
        if (flag)
        {
            int s = 0;
            for (int j = 1; j <= n; j++)
                s += all[i][j];
            ans = max(ans, s);
        }
    }
    printf("%d\n", ans);
    return 0;
}