#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const ll Inf = 1000000000000000000ll;
const int Maxn = 200005;
const int Maxm = 1048576;

struct node {
    ll add;
    lli mn;
};

int n, D;
int a[2][Maxn];
node st[2][Maxm];
map <int, ll> M[2];
ll res;

void downOn(int s, int v, ll fl)
{
    st[s][v].add += fl;
    st[s][v].mn.first += fl;
}

void Down(int s, int v)
{
    if (st[s][v].add) {
        downOn(s, 2 * v, st[s][v].add);
        downOn(s, 2 * v + 1, st[s][v].add);
        st[s][v].add = 0;
    }
}

void Union(int s, int v)
{
    st[s][v].mn = min(st[s][2 * v].mn, st[s][2 * v + 1].mn);
}

void Create(int s, int v, int l, int r)
{
    st[s][v].add = 0;
    if (l == r) {
        st[s][v].mn.first = a[s][l] - ll(l) * D;
        st[s][v].mn.second = l;
    } else {
        int m = l + r >> 1;
        Create(s, 2 * v, l, m);
        Create(s, 2 * v + 1, m + 1, r);
        Union(s, v);
    }
}

void Update(int s, int v, int l, int r, int a, int b, ll add)
{
    if (l == a && r == b) downOn(s, v, add);
    else {
        Down(s, v);
        int m = l + r >> 1;
        if (a <= m) Update(s, 2 * v, l, m, a, min(m, b), add);
        if (m + 1 <= b) Update(s, 2 * v + 1, m + 1, r, max(m + 1, a), b, add);
        Union(s, v);
    }
}

void Insert(int s, int x, ll val)
{
    map <int, ll>::iterator it = M[s].upper_bound(x);
    if (it->second <= val) return;
    ll oldval = it->second;
    int cur = x;
    it--;
    Update(s, 1, 0, n - 1, it->first + 1, cur, val - oldval);
    while (val <= it->second) {
        cur = it->first;
        oldval = it->second;
        M[s].erase(it--);
        Update(s, 1, 0, n - 1, it->first + 1, cur, val - oldval);
    }
    M[s][x] = val;
}

void Init()
{
    for (int s = 0; s < 2; s++) {
        Create(s, 1, 0, n - 1);
        M[s][-1] = -Inf; M[s][n] = Inf;
        Update(s, 1, 0, n - 1, 0, n - 1, Inf);
    }
}

int main()
{
    scanf("%d %d", &n, &D);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[0][i]);
        a[1][n - 1 - i] = a[0][i];
    }
    Init();
    int v = 0;
    for (int i = 0; i < n - 1; i++) {
        int ov = n - 1 - v;
        Update(0, 1, 0, n - 1, v, v, Inf);
        Update(1, 1, 0, n - 1, ov, ov, Inf);
        ll myval = a[0][v] + ll(v) * D;
        Insert(0, v, myval);
        ll omyval = a[1][ov] + ll(ov) * D;
        Insert(1, ov, omyval);
        lli A = st[0][1].mn;
        lli B = st[1][1].mn;
        if (A <= B) { res += A.first; v = A.second; }
        else { res += B.first; v = n - 1 - B.second; }
    }
    cout << res << endl;
    return 0;
}
