///not today

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef pair<long long, long long> pll;

#define SZ(x) (int)(x).size()
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define int long long
#define accept_sho ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define lc (v << 1)
#define rc ((v << 1)| 1)
#define mid ((R + L) >> 1)

const int maxn = 3e2 + 2;
int dp[maxn][maxn][maxn];

int32_t main(){
      string s;
      int K, n;
      cin >>s >>K;
      n = SZ(s);
      for(int k = 0; k <= K; k ++){
      for(int j = 0; j < n; j ++){
      for(int i = 0; i + j < n; i ++){
                        dp[k][j][i] = 1;
                        if(j == 0)
                              continue;
                        if(s[i] == s[i + j]){
                              if(j > 1){
                                    dp[k][j][i] = dp[k][j - 2][i + 1] + 2;
                              }
                              else{
                                    dp[k][j][i] = 2;
                              }
                        }
                        else{
                              xmax(dp[k][j][i], dp[k][j - 1][i]);
                              xmax(dp[k][j][i], dp[k][j - 1][i + 1]);
                              if(k){
                                    if(j > 1){
                                          xmax(dp[k][j][i], dp[k - 1][j - 2][i + 1] + 2);
                                    }
                                    else{
                                          dp[k][j][i] = 2;
                                    }
                              }
                        }
      }
      }
      }
      cout <<dp[K][n - 1][0] <<endl;
}
