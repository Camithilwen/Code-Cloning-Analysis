#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 123455, LG = 60;
ll n, m, k, A[N], P[N], R[LG][N];
int main()
{
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &A[i]), P[i] = i;
    scanf("%lld%lld", &m, &k);
    for (int i = 0; i < m; i++)
    {
        int a;
        scanf("%lld", &a);
        swap(P[a], P[a - 1]);
    }
    for (int i = 0; i < n; i++)
        R[0][i] = P[i];
    for (int j = 1; j < LG; j++)
        for (int i = 0; i < n; i++)
            R[j][i] = R[j - 1][R[j - 1][i]];
    printf("%lld\n", A[0]); ll nw = A[0];
    for (int i = 1; i < n; i++)
    {
        int id = i;
        for (int j = 0; j < LG; j++)
            if ((k >> j) & 1LL)
                id = R[j][id];
        nw += A[id] - A[id - 1];
        printf("%lld\n", nw);
    }
    return 0;
}