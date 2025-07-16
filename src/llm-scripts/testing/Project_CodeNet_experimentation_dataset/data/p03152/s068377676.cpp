#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

int N, M;
int A[1010], B[1010];
int C[1010101];

int belongs_a(int n)
{
    auto lb = lower_bound(A, A + N, n);
    int i = lb - begin(A);
    if (A[i] == n)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int greater_num_a(int n)
{
    auto lb = upper_bound(A, A + N, n);
    int i = lb - begin(A);
    return N - i;
}

int belongs_b(int m)
{
    auto lb = lower_bound(B, B + M, m);
    int i = lb - begin(B);
    if (B[i] == m)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int greater_num_b(int m)
{
    auto lb = upper_bound(B, B + M, m);
    int i = lb - begin(B);
    return M - i;
}

int main()
{
    cin >> N >> M;
    rep(i, 0, N)
    {
        cin >> A[i];
    }
    rep(i, 0, M)
    {
        cin >> B[i];
    }
    sort(A, A + N);
    sort(B, B + M);
    rep(i, 1, N)
    {
        if (A[i - 1] == A[i])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    rep(i, 1, M)
    {
        if (B[i - 1] == B[i])
        {
            cout << 0 << endl;
            return 0;
        }
    }

    ll ans = 1;
    for (int i = N * M; i >= 1; i--)
    {
        int ba = belongs_a(i);
        int bb = belongs_b(i);
        if (ba >= 0 && bb >= 0)
        {
            continue;
        }
        else if (ba >= 0)
        {
            ans *= greater_num_b(i);
            ans %= MOD;
        }
        else if (bb >= 0)
        {
            ans *= greater_num_a(i);
            ans %= MOD;
        }
        else
        {
            ll p = greater_num_a(i) * greater_num_b(i) % MOD;
            p = (p - (M * N - i) + MOD) % MOD;
            ans *= p;
            ans %= MOD;
        }
    }
    cout << ans << endl;
}