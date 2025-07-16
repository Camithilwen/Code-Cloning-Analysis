#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 5;

int n, m, a[N], label[N], label2[N];
ll k;
ll x[N], d[N], ans[N];

vector <vector <int> > cycles;
bool vis[N];
void DFS(int v)
{
    cycles.back().pb(v);
    vis[v] = true;
    if(vis[label[v]])
        return;
    DFS(label[v]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
        d[i] = x[i] - x[i - 1];
        label[i] = i;
    }

    cin >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i];
        swap(label[a[i]], label[a[i] + 1]);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            cycles.pb(vector <int> ());
            DFS(i);
        }
    }

    for(int i = 0; i < cycles.size(); i++)
    {
        int sz = k % (int)cycles[i].size();
        for(int j = 0; j < cycles[i].size(); j++)
            label2[cycles[i][(j + sz) % cycles[i].size()]] = cycles[i][j];
    }

    for(int i = 1; i <= n; i++)
        ans[label2[i]] = d[i];

    for(int i = 1; i <= n; i++)
        ans[i] = ans[i] + ans[i - 1];

    for(int i = 1; i <= n; i++)
        cout << fixed << setprecision(9) << ans[i] << endl;

    return 0;
}
