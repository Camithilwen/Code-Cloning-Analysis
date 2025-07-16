#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int N, M;
int a[300], b[300], c[300];

int g[15][15];

ll dp[1<<15][15];
const ll INF = 1e+12;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N >> M;
    int sum = 0;
    for(int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        g[a[i]][b[i]] = c[i];
        g[b[i]][a[i]] = c[i];
        sum += c[i];
    }
    int fin = (1<<N)-1;
    for(int i = 1; i < (1<<N); i++){
        if(i%2 == 0) continue;
        for(int j = 0; j < N; j++){
            if(!(i&(1<<j))) continue;
            for(int k = j+1; k < N; k++){
                if(!(i&(1<<k))) continue;
                dp[i][0] += g[j][k];
            }
        }
    }
    for(int i = 1; i < (1<<N); i++){
        for(int j = 0; j < N; j++){
            if(i == 1 && j == 0) continue;
            if(dp[i][j] == 0) dp[i][j] = -INF;        
        }
    }
    for(int i = 1; i < (1<<N); i++){
        if(i%2 == 0) continue;
        if(i&(1<<(N-1))) continue;
        for(int j = (i+1)|i; j < (1<<N); j = (j+1)|i){
            int rem = j-i;
            ll sum_rem = 0;
            for(int k = 0; k < N; k++){
                for(int l = k+1; l < N; l++){
                    if((rem&(1<<k)) && (rem&(1<<l))) sum_rem += g[k][l];
                }
            }
            // cout << i << '-' << j << ' ' << rem << ' ' << sum_rem << endl;
            if(j&(1<<(N-1))){
                // N-1に行く
                for(int k = 0; k < N; k++){
                    if(!(i&(1<<k))) continue;
                    if(g[k][N-1] == 0) {}
                    else{
                        // if(i == 7) cout << i << "at"<< k << "dp" << dp[i][k] << '-' << j << endl;
                        dp[j][N-1] = max(dp[j][N-1], dp[i][k]+sum_rem+g[k][N-1]);
                    }
                }
            }else{
                // k -> l
                for(int k = 0; k < N; k++){
                    if(!(i&(1<<k))) continue;
                    for(int l = 0; l < N; l++){
                        if(!(rem&(1<<l))) continue;
                        if(g[k][l] == 0) {}
                        else{
                            dp[j][l] = max(dp[j][l], dp[i][k]+sum_rem+g[k][l]);
                        }
                    }
                }
            }
        }
    }
    ll g_max = 0;
    for(int i = 0; i < (1<<N); i++){
        g_max = max(g_max, dp[i][N-1]);
        // cout << dp[i][N-1] << endl;
    }
    cout << sum-g_max << endl;
}