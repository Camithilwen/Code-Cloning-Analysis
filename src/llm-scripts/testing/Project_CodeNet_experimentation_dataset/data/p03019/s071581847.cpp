#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N, X, b[maxN], p[maxN], l[maxN], r[maxN];
/*int lg, N, X, aib[2 * maxN], val[2 * maxN];
long long aibSum[2 * maxN], ans = 1LL << 60;
pair < int, int > h[2 * maxN];
pair < int, pair < int, int > > v[maxN];

set < int > S;
void able (int pos, int x)
{
    ///val = +-1 (aka enable or disable)
    if (x < 0) S.erase (pos);
    else S.insert (pos);
    int y = val[pos] * x;
    while (pos <= 2 * N)
        aibSum[pos] += y,
        aib[pos] += x,
        pos += pos - (pos & (pos - 1));
}

void attempt (long long need)
{
    ///max aibSum * X < need
    int pos = 0, used = 0;
    for (int i=lg; i>=0; i--)
        if (pos + (1 << i) <= 2 * N && 1LL * X * aibSum[pos + (1 << i)] < need)
            pos |= 1 << i, need -= 1LL * X * aibSum[pos], used += aib[pos];
    for (auto it : S)
        printf ("%d ", it);
    printf ("? >= %d\n", pos);
    auto it = S.lower_bound (pos + 1);
    assert (it != S.end ());
    int leftover = (need + val[*it] - 1) / val[*it];
    long long curr = 1LL * X * used + leftover;
    if (curr < ans)
        ans = curr;
}*/

long long f (int i)
{
    return 1LL * (X - b[i]) * r[i] + 1LL * b[i] * l[i];
}

bool cmp (int i, int j)
{
    return f (i) > f (j);
}

bool ok (long long moves)
{
    int cnt = moves / X, smth = moves % X;
    long long toOvercome = 0;
    for (int i=1; i<=N; i++)
        toOvercome += 1LL * l[i] * b[i];
    long long firstCntSum = 0;
    for (int i=1; i<=cnt; i++)
        firstCntSum += f(p[i]);
    for (int i=1; i<=N; i++)
    {
        ///assume i is smth
        long long curr = toOvercome;
        int pos = p[i];
        if (b[pos] >= smth) curr -= 1LL * smth * l[pos];///unimportant
        else curr += 1LL * b[pos] * (r[pos] - l[pos]), curr -= (1LL * smth * r[pos]);
        curr -= firstCntSum;
        if (i <= cnt)
            curr -= f (p[cnt + 1]) - f (pos); ///this should've been in firstCntSum
        if (curr <= 0)
            return 1;
    }
    return 0;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &X);
/*for (int i=1; i<=N; i++)
    scanf ("%d %d %d", &v[i].first, &v[i].second.first, &v[i].second.second);
sort (v + 1, v + N + 1, cmp);
for (int i=1; i<=N; i++)
    h[2 * i - 1] = {-v[i].second.first, i},
    h[2 * i] = {-v[i].second.second, -i};
sort (h + 1, h + 2 * N + 1);
for (int i=1; i<=2 * N; i++)
{
    val[i] = -h[i].first;
    if (h[i].second > 0) v[h[i].second].second.first = i;
    else v[-h[i].second].second.second = i;
}
lg = 0;
while ((2 << lg) <= 2 * N)
    lg ++;
long long opponentValue = 0;
for (int i=1; i<=N; i++)
    opponentValue += 1LL * v[i].first * val[v[i].second.first],
    able (v[i].second.first, +1); ///all unimportant
attempt (opponentValue);
for (int i=1; i<=N; i++)
    opponentValue += 1LL * v[i].first * (val[v[i].second.second] - val[v[i].second.first]),
    able (v[i].second.first, -1),
    able (v[i].second.second, +1),
    attempt (opponentValue);
printf ("%lld\n", ans);*/
for (int i=1; i<=N; i++)
    scanf ("%d %d %d", &b[i], &l[i], &r[i]), p[i] = i;
sort (p + 1, p + N + 1, cmp);
{
    long long p = 0, u = 1LL * N * X - 1, mid, ras = 1LL * N * X;
    while (p <= u)
    {
        mid = (p + u) >> 1;
        if (ok (mid))
            ras = mid, u = mid - 1;
        else p = mid + 1;
    }
    printf ("%lld\n", ras);
}
return 0;
}
