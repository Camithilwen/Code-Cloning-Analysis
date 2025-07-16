#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 5050;
const ll INF = 0x3f3f3f3f;

ll dp[N][N];
int n, w[N], h[N], a[N], ans;

bool cmp(int A,int B){
    return w[A] + h[A] < w[B] + h[B];
}

int main(){
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        scanf("%d%d", h + i, w + i);a[i] = i;
    }
    sort(a, a + n, cmp);
    for(int i = 0;i<=n;i++){
        dp[0][i] = INF * INF;
        dp[i][0] = 0;
    }
    dp[0][1] = w[a[0]];
    for(int i = 1;i<n;i++){
        for(int j = 1;j<=n;j++){
            dp[i][j] = dp[i - 1][j];
            if(h[a[i]] >= dp[i - 1][j - 1])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + w[a[i]]);
        }
    }
    ans = n;
    while(dp[n - 1][ans] == INF * INF) ans--;
    printf("%d\n", ans);
}
