#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const ll M = 4e18;

ll n, m, mn = M;
vector<ll> ve[1005];
vector<ll> ans;
vector<ll> now;
ll vv[1005];

void dfs(ll p)
{
    if(now.size() != 0 && p == now[0])
    {
        if(mn > now.size())
        {
            mn = now.size();
            ans = now;
        }
        return;
    }
    else if(vv[p]) return;
    if(now.size() > mn) return;
    vv[p] = true;
    now.push_back(p);
    for(ll i = 0; i < ve[p].size(); i++)
    {
        dfs(ve[p][i]);
    }
//    vv[p] = false;
    now.pop_back();
}

int main()
{
    scanf("%lld%lld", &n, &m);
    for(ll i = 0; i < m; i++)
    {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        ve[u].push_back(v);
    }
    for(ll i = 1; i <= n; i++)
    {
        for(ll i = 1; i <= n; i++) vv[i] = false;
        dfs(i);
    }
    if(mn == M) printf("-1\n");
    else
    {
        printf("%lld\n", mn);
        for(ll i = 0; i < ans.size(); i++)
        {
            printf("%lld\n", ans[i]);
        }
    }
    return 0;
}
