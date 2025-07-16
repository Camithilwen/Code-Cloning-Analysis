#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define pii pair < int, int >
#define pb push_back
#define ll long long
#define int ll

const int inf = (int)1e18 + 7;

pii ar[5234];
int dp[5234];
int x;

bool comp (const pii &a, const pii &b) {
    return a.fr + a.sc < b.fr + b.sc;
}

main () {
    int n; scanf ("%lld", &n);
    for (int i = 1; i <= n; i++) {
        int a, b; scanf ("%lld %lld", &a, &b);
        ar[i] = {a, b};
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = inf;
    }
    sort(ar + 1, ar + n + 1, comp);
    dp[0] = x;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            if (ar[i].fr >= dp[j - 1]) {
                dp[j] = min(dp[j], dp[j - 1] + ar[i].sc);
            }
        }
    }
    vector < int > ans;
    while (dp[n] == inf) n--;
    printf ("%lld\n", n);
    return 0;
    while (n > 1) {
        for (int i = n - 1; i >= 1; i--) {
            if (dp[n] == dp[i] + ar[i].sc) {
                cout << i << ' ';
                n = i;
                break;
            }
        }
    }
    for (int to : ans) {
        printf ("%d ", to);
    }
}
