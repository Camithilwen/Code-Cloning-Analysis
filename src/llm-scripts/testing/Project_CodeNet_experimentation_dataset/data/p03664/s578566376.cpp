#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

const int N = 16;
const int M = (1 << N);
const int INF = 0x3f3f3f3f;

int dp[N][M], g[N][N], n, m, rv[M];

int f(int st, int msk){
    if(st == n - 1) return 0;
    if(dp[st][msk] != -1) return dp[st][msk];
    int sol = INF;
    for(int msk1 = (msk - 1) & msk; msk1 ; msk1 = (msk1 - 1) & msk){
        int msk2 = msk ^ msk1;
        if(msk1 & (1 << (n - 1))) continue;
        if(msk2 & (1 << st)) continue;
        int sum = 0;
        for(int t1 = msk1; t1 ; t1 -= t1 & (-t1)){
            for(int t2 = msk2 ; t2 ; t2 -= t2 & (-t2)){
                sum += g[rv[t1 & (-t1)]][rv[t2 & (-t2)]];
            }
        }
        for(int t2 = msk2 ; t2 ; t2 -= t2 & (-t2)){
            if(g[st][rv[t2 & (-t2)]]){
                sol = min(sol, f(rv[t2 & (-t2)], msk2) + sum - g[st][rv[t2 & (-t2)]]);
            }
        }

    }
    return dp[st][msk] = sol;
}

int main(){
    memset(dp, -1, sizeof(dp));
    for(int i = 0;i<N;i++) rv[(1 << i)] = i;
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &n, &m);
    for(int i = 0;i<m;i++){
        int x, y;scanf("%d%d", &x, &y);x--;y--;
        scanf("%d", &g[x][y]);
        g[y][x] = g[x][y];
    }
    printf("%d\n", f(0, (1 << n) - 1));
}
