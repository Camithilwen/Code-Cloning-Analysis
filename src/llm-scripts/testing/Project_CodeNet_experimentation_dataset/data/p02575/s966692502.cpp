#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define fillarray(array, value, begin, end) fill((array) + (begin), (array) + (end) + 1, value)
#define fillvector(v, value) fill((v).begin(), (v).end(), value)
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
#define vecfirst (*vec.begin())
#define veclast (*vec.rbegin())
#define vecall(v) (v).begin(), (v).end()
#define vecupsort(v) (sort((v).begin(), (v).end()))
#define vecdownsort(v, type) (sort(vecall(v), greater<type>()))
#define veccmpsort(v, cmp) (sort(vecall(v), cmp))
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end()
{
#ifdef ONLINE
    printf("\nTime used: %.6lf(s)\n", ((double)TIME__END - TIME__START) / 1000);
    system("pause");
#endif
}
int h, w;
int A[N], B[N], cnt[N];
map<int, int> c;

inline void solve()
{
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; ++i)
        scanf("%d%d", &A[i], &B[i]);
    for (int i = 1; i <= w; ++i)
        c.insert(mp(i, i));
    int ans = 0;
    cnt[0] = w;
    for (int i = 1; i <= h; ++i)
    {
        int L = A[i], R = B[i];
        auto it = c.lower_bound(L);
        int pos = 0;
        while (it != c.end() && it->first <= R + 1)
        {
            pos = max(pos, it->second);
            cnt[it->first - it->second]--;
            it = c.erase(it);
        }
        if (pos && R + 1 <= w)
        {
            cnt[R + 1 - pos]++;
            c.insert(mp(R + 1, pos));
        }
        while (!cnt[ans] && ans < w)
            ans++;
        if (ans == w)
            puts("-1");
        else
            printf("%d\n", ans + i);
    }
}

int main()
{
    TIME__START = clock();
    int Test = 1;
    // scanf("%d", &Test);
    while (Test--)
        solve();
    TIME__END = clock();
    program_end();
    return 0;
}