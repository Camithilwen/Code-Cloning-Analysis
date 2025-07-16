#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//FILE *fi = freopen("1.txt", "r", stdin);
//FILE *fo = freopen("1", "w", stdout);
//FILE *fi = freopen("P.inp", "r", stdin);
//FILE *fo = freopen("P.out", "w", stdout);
int n, Q;
int c[500001];
typedef pair<int, int> ii;
vector<ii> q[500001];
int bit[500001];
void update(int pos, int val)
{
    for (int i = pos; i <= n; i += i & -i)
        bit[i] += val;
}
int Get(int pos)
{
    int ans = 0;
    for (int i = pos; i; i -= i & -i)
        ans += bit[i];
    return ans;
}
int ans[500001];
int b[500001];
int main()
{
    //------------------------------
    // Faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //------------------------------
    cin >> n >> Q;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    int id = 0;
    for (int i = 1; i <= Q; i++)
    {
        int l, r;
        ++id;
        cin >> l >> r;
        q[r].push_back({l, id});
    }
    for (int i = 1; i <= n; i++)
    {
        int x = c[i];
        if (b[x])
            update(b[x], -1);
        b[x] = i;
        update(b[x], 1);
        for (auto Q : q[i])
        {
            ans[Q.second] = Get(n) - Get(Q.first - 1);
        }
    }
    for (int i = 1; i <= Q; i++)
        cout << ans[i] << "\n";
    return 0;
}