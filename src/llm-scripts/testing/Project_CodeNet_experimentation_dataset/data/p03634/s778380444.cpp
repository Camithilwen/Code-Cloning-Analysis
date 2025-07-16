#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vp vector<pair<int, int>>
#define vll vector<long long>
#define inf 1000000100
#define infll 1LL << 50

ll gcd(ll a, ll b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    return a/g * b; //prevent overflow
}

/////////////////////////  END OF TEMPLATE /////////////////////////////////////////

vp adj[100001];

bool visited[100001];
vll dist(100001);
void dfs(int k)
{
    visited[k] = 1;
    for(auto u : adj[k])
    {
        if(!visited[u.first])
        {
            dist[u.first] = dist[k] + u.second;
            dfs(u.first);
        }

    }

}


int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n-1; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }

    int q, k;
    cin >> q >> k;
    dfs(k);
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        cout << dist[x] + dist[y] << endl;
    }
}