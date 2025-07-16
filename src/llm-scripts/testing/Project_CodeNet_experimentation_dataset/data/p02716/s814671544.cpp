#include <bits/stdc++.h>
using namespace std;
#define elif else if
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << (x) << endl
#define TGET(a, b) get<b>(a)

#define MAXN 200100

ll arr[MAXN] = {0};
ll odd_pos[MAXN] = {0};
ll even_pos[MAXN] = {0};

ll dp[MAXN] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", arr + i);
    }

    for (int i = 1; i <= n; i += 2)
    {
        if (i == 1)
        {
            odd_pos[i] = arr[i];
            even_pos[i + 1] = arr[i + 1];
        }
        else
        {
            odd_pos[i] = arr[i] + odd_pos[i - 2];
            even_pos[i + 1] = arr[i + 1] + even_pos[i - 1];
        }
    }
    // ll ans = even_pos[n-1];
    // for (int i = 1; i <= n; i += 2)
    // {
    //     ans = max(ans, odd_pos[n] - arr[i]);
    //     ans = max(ans, (odd_pos[i] - arr[i]) + (even_pos[n - 1] - even_pos[i - 1]));
    //     ans = max(ans, (odd_pos[i] - arr[i]) + arr[i + 1] + (odd_pos[n] - odd_pos[i + 2]));
    // }
    // printf("%ld\n", ans);
    for (int i = 2; i <= n; i++)
    {
        if (i % 2)
        {
            dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
        }
        else
        {
            dp[i] = max(odd_pos[i - 1], dp[i - 2] + arr[i]);
        }
    }
    printf("%lld\n", dp[n]);

    return 0;
}