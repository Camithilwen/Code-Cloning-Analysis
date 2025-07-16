#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
int a[N+5], dp[N+5], cnt;

int main(){
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", a+i);
    }
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i){
        int pos = upper_bound(dp + 1, dp + cnt + 1, a[i]) - dp;
        dp[pos] = a[i]; cnt = max(cnt, pos);
    }
    printf("%d\n", cnt);
    return 0;
}