#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 100005;
const int Maxm = 524288;

int n, x;
int b[Maxn], l[Maxn], u[Maxn];
lli seq[Maxn];
ll cur;
ll st[Maxm], cnt[Maxm];
ll res;

ll Get(int ind, int y)
{
    if (y <= b[ind]) return ll(l[ind]) * y;
    return ll(y - b[ind]) * u[ind] + ll(l[ind]) * b[ind];
}

void Union(int v)
{
    st[v] = st[2 * v] + st[2 * v + 1];
    cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
}

void Create(int v, int l, int r)
{
    if (l == r) { st[v] = seq[l].first; cnt[v] = 1; }
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        Union(v);
    }
}

void Update(int v, int l, int r, int x, bool add)
{
    if (l == r)
        if (add) { st[v] = seq[l].first; cnt[v] = 1; }
        else st[v] = cnt[v] = 0;
    else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x, add);
        else Update(2 * v + 1, m + 1, r, x, add);
        Union(v);
    }
}

lli Get(int v, int l, int r, ll val)
{
    if (val >= 0) return lli(0, 0);
    else if (l == r) return lli(st[v], cnt[v]);
    else {
        lli res = lli(0, 0);
        int m = l + r >> 1;
        if (val + st[2 * v + 1] >= 0)
            return Get(2 * v + 1, m + 1, r, val);
        else {
            res = lli(st[2 * v + 1], cnt[2 * v + 1]);
            lli got = Get(2 * v, l, m, val + st[2 * v + 1]);
            res.first += got.first; res.second += got.second;
            return res;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &b[i], &l[i], &u[i]);
        cur -= ll(b[i]) * l[i];
        seq[i] = lli(ll(b[i]) * l[i] + ll(x - b[i]) * u[i], i);
    }
    res = ll(n) * x;
    sort(seq, seq + n);
    Create(1, 0, n - 1);
    for (int i = 0; i < n; i++) {
        Update(1, 0, n - 1, i, false);
        lli got = Get(1, 0, n - 1, cur + seq[i].first);
        int lef = 0, rig = x;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (cur + got.first + Get(seq[i].second, mid) >= 0)
                rig = mid - 1;
            else lef = mid + 1;
        }
        res = min(res, ll(x) * got.second + ll(rig + 1));
        Update(1, 0, n - 1, i, true);
    }
    cout << res << endl;
    return 0;
}
