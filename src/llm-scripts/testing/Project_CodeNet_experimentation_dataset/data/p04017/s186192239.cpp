#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int x[MAXN], st[MAXN][18];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    int L, Q; scanf("%d%d", &L, &Q);
    // memset(st, 0x3f3f3f3f, sizeof(st));
    for (int i = 1; i <= n; i++)
        st[i][0] = min(n, (int)(upper_bound(x + 1, x + 1 + n, x[i] + L) - x - 1));

    
    for (int j = 1; j < 18; j++)
        for (int i = 1; i <= n; i++)
            st[i][j] = st[st[i][j - 1]][j - 1];
    while (Q--)
    {
        int l, r; scanf("%d%d", &l, &r);
        if (l > r) swap(l, r);
        int res = 0;
        for (int j = 17; j >= 0; j--)
            if (st[l][j] < r) res += (1 << j), l = st[l][j];
        printf("%d\n", res + 1);
    }
    return 0;
}