#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 1; i <= (n); ++i)
#define rag(con) std::begin(con), std::end(con)

constexpr int MAX = 1010;

std::vector<int> to[MAX];

int main()
{
    int n, m;
    std::cin >> n >> m;

    rep(i, m)
    {
        int a, b;
        std::cin >> a >> b;
        to[a].push_back(b);
    }

    std::vector<int> ans(n + 1);
    constexpr int INF = 1e9;

    rep(i, n)
    {
        std::queue<int> que;

        std::vector<int> dis(n + 1, INF);
        std::vector<int> par(n + 1);

        que.push(i);
        dis[i] = 0;

        while (!que.empty())
        {

            int x = que.front();
            que.pop();

            for (auto u : to[x])
            {
                if (dis[u] > dis[x] + 1)
                {
                    dis[u] = dis[x] + 1;
                    par[u] = x;
                    que.push(u);
                }
                else if (dis[u] == 0)
                    par[u] = x;
            }
        }
        if (!par[i])
            continue;
        int v = par[i];
        std::vector<int> vec;
        while (v != i)
        {
            vec.push_back(v);
            v = par[v];
        }
        vec.push_back(i);
        if (ans.size() > vec.size())
            ans = vec;
    }

    if (ans.size() == n + 1)
        std::cout << -1 << std::endl;
    else
    {
        std::cout << ans.size() << std::endl;
        for (auto x : ans)
            std::cout << x << std::endl;
    }

    return 0;
}