#include <bits/stdc++.h>

#define PB emplace_back

using namespace std;

const int N = 17;

long long int a[N][N], dp[1<<N];

int main () {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++ ) {
        for(int j = 0 ; j < n ; j++ ) {
            cin >> a[i][j];
        }
    }
    long long int ans = -1e18;
    for(int i = 1 ; i < (1 << n ) ; i++ ) {
        long long int mas = 0;
        vector<int>v;
        for(int j = 0 ; j < n ; j++ ) {
            if((1<<j)&i) v.PB(j);
        }
        for(int u: v) {
            for(int uu: v) {
                if(u <= uu)continue;
                mas += a[u][uu];
            }
        }
        for(int j = i ; j > 0 ; j = (j - 1) & i) {
            mas = max(mas, dp[j] + dp[i^j]);
        }
        if(ans < mas)ans = mas;
        dp[i] = mas;
    }
    cout << ans;
}
