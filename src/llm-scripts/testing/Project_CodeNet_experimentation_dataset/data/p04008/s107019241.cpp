#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
int n,k,head[maxn],to[maxn],nextt[maxn],tot = 1,ans;

void add(int x,int y)
{
    to[tot] = y;
    nextt[tot] = head[x];
    head[x] = tot++;
}

int dfs(int u,int faa,int from)
{
    int res = 0;
    for (int i = head[u];i;i = nextt[i])
    {
        int v = to[i];
        if (v == faa)
            continue;
        res = max(res,dfs(v,u,from) + 1);
    }
    if (u != from && res >= k - 1)
    {
        ans++;
        return -1;
    }
    else
        return res;
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d",&x);
        if (i == 1)
        {
            if (x != 1)
                ans++;
        }
        else
            add(x,i);
    }
    for (int i = head[1];i;i = nextt[i])
        dfs(to[i],1,to[i]);
    printf("%d\n",ans);

    return 0;
}
