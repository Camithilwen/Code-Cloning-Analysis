#ifdef APTEST
#include "debug_tools/program.h"
#endif
#include <iostream>
using namespace std;
const unsigned int maxn = 100000, maxm = 100000;

struct edge
{
    unsigned int to;
    const edge* pre;
} ed[maxm * 2 + 1];
const edge* head[maxn + 1];
unsigned long long siz[2][maxn + 1];
bool col[maxn + 1], vis[maxn + 1];

void addEdge(const unsigned int from, const unsigned int to)
{
    static edge* cur = ed;
    cur->to = to;
    cur->pre = head[from];
    head[from] = cur;
    ++cur;
}
bool dfs(const unsigned int x, const unsigned int sta)
{
    ++siz[col[x]][sta];
    vis[x] = true;
    bool ret = true;
    for (const edge* i = head[x]; i; i = i->pre)
    {
        const unsigned int to = i->to;
        if (vis[to])
        {
            if (col[to] == col[x])
                ret = false;
            continue;
        }
        col[to] = !col[x];
        ret &= dfs(to, sta);
    }
    return ret;
}
int main()
{
#ifndef APTEST
    ios_base::sync_with_stdio(false);
#endif
    unsigned int n, m;
    cin >> n >> m;
    for (unsigned int i = 0; i < m; ++i)
    {
        unsigned int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    unsigned long long ret = 0;
    for (unsigned int i = 1; i <= n; ++i)
        if (!vis[i])
        {
            const bool typ = dfs(i, i);
            const unsigned long long s = siz[0][i] + siz[1][i];
            ret += typ ? siz[0][i] * siz[1][i] : s * (s - 1) / 2;
        }
    cout << ret - m << endl;
    return 0;
}