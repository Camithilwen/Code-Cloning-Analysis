#include <bits/stdc++.h>

#define N_MAX 200002
#define Q_MAX 200002

#define ll long long

using namespace std;

const ll INF = 1000000000000000;

int n, q, a, b;

int pos[Q_MAX];

struct SGTNode
{
    ll mindp;
    ll min1, min2;
    ll lazy;
};

SGTNode dp[N_MAX * 3];

void split (int node)
{
    int lson = (node << 1), rson = (lson | 1);
    dp[lson].mindp += dp[node].lazy;
    dp[lson].min1 += dp[node].lazy;
    dp[lson].min2 += dp[node].lazy;
    dp[lson].lazy += dp[node].lazy;
    dp[rson].mindp += dp[node].lazy;
    dp[rson].min1 += dp[node].lazy;
    dp[rson].min2 += dp[node].lazy;
    dp[rson].lazy += dp[node].lazy;
    dp[node].lazy = 0;
}

SGTNode join (SGTNode a, SGTNode b)
{
    SGTNode ans;
    ans.mindp = min(a.mindp, b.mindp);
    ans.min1 = min(a.min1, b.min1);
    ans.min2 = min(a.min2, b.min2);
    ans.lazy = 0;
    return ans;
}

void update (int node, int l, int r, int ul, int ur, ll val)
{
    if(ul <= l && r <= ur)
    {
        dp[node].mindp += val;
        dp[node].min1 += val;
        dp[node].min2 += val;
        dp[node].lazy += val;
        return;
    }
    int mid = (l + r) / 2, lson = (node << 1), rson = (lson | 1);
    split(node);
    if(ul <= mid)
        update(lson, l, mid, ul, ur, val);
    if(mid + 1 <= ur)
        update(rson, mid + 1, r, ul, ur, val);
    dp[node] = join(dp[lson], dp[rson]);
}

void update1 (int node, int l, int r, int pos, ll val)
{
    if(l == r)
    {
        dp[node].mindp = val;
        dp[node].min1 = val - pos;
        dp[node].min2 = val + pos;
        return;
    }
    int mid = (l + r) / 2, lson = (node << 1), rson = (lson | 1);
    split(node);
    if(pos <= mid)
        update1(lson, l, mid, pos, val);
    if(mid + 1 <= pos)
        update1(rson, mid + 1, r, pos, val);
    dp[node] = join(dp[lson], dp[rson]);
}


SGTNode query (int node, int l, int r, int ql, int qr)
{
    if(ql <= l && r <= qr)
        return dp[node];
    int mid = (l + r) / 2, lson = (node << 1), rson = (lson | 1);
    split(node);
    if(ql <= mid && mid + 1 <= qr)
        return join(query(lson, l, mid, ql, qr), query(rson, mid + 1, r, ql, qr));
    else if(ql <= mid)
        return query(lson, l, mid, ql, qr);
    else
        return query(rson, mid + 1, r, ql, qr);
}

int main()
{
    cin >> n >> q >> a >> b;
    for(int i = 1; i <= q; i++)
        cin >> pos[i];
    pos[0] = a;
    for(int i = 1; i < N_MAX * 3; i++)
        dp[i].min1 = dp[i].min2 = dp[i].mindp = INF;
    update1(1, 1, n, b, 0);
    for(int i = 1; i <= q; i++)
    {
        ll diff = abs(pos[i] - pos[i - 1]);
        ll mi = min(query(1, 1, n, pos[i], pos[i]).mindp + diff, min(query(1, 1, n, 1, pos[i]).min1 + pos[i], query(1, 1, n, pos[i], n).min2 - pos[i]));
        if(pos[i - 1] - 1 >= 1)
            update(1, 1, n, 1, pos[i - 1] - 1, diff);
        if(pos[i - 1] + 1 <= n)
            update(1, 1, n, pos[i - 1] + 1, n, diff);
        update1(1, 1, n, pos[i - 1], mi);
        update1(1, 1, n, pos[i], INF);
    }
    cout << dp[1].mindp << "\n";
    return 0;
}
