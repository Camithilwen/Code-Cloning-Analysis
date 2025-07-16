#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = (int) 1e5 + 100;

vector <int> ch[N];
int k;

struct Ans
{
    vector <int> v;

    Ans() : v({0}) {}

    void eprint()
    {
        for (int i = 0; i < min(k + 1, (int) v.size()); i++)
            eprintf("[%d] %d, ", i, v[(int) v.size() - 1 - i]);
        eprintf("\n");
    }
};


Ans dp[N];


int merge(int a, int b)
{
    if ((int) dp[a].v.size() < (int) dp[b].v.size())
        swap(a, b);

    for (int i = 0; i < (int) dp[b].v.size(); i++)
        dp[a].v[(int) dp[a].v.size() - 1 - i] += dp[b].v[(int) dp[b].v.size() - 1 - i];

    return a;
}

int goUp(int a)
{
    dp[a].v.push_back(1);
    if ((int) dp[a].v.size() >= k + 1)
        dp[a].v.back() += dp[a].v[(int) dp[a].v.size() - k - 1];

    int i = 2;
    while (i <= (int) dp[a].v.size() && dp[a].v[(int) dp[a].v.size() - i] > dp[a].v.back())
    {
        dp[a].v[(int) dp[a].v.size() - i] = dp[a].v.back();
        i++;
    }

    return a;
}

int solve(int v)
{
    int cur = v;
    for (int to : ch[v])
    {
        int nx = solve(to);
        cur = merge(cur, nx);
    }
    //eprintf("(%d): ", v); dp[cur].eprint();
    if (v != 0)
        cur = goUp(cur);
    //eprintf("(%d'): ", v); dp[cur].eprint();
    return cur;
}

int a[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i]--;
    }

    for (int i = 1; i < n; i++)
        ch[a[i]].push_back(i);

    int id = solve(0);

    int ans = dp[id].v[max(0, (int) dp[id].v.size() - k - 1)];

    if (a[0] != 0)
        ans++;

    printf("%d\n", ans);

	return 0;
}


