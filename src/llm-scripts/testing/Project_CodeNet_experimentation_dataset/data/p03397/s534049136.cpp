#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define space putchar(' ')
#define enter putchar('\n')
#define mp make_pair
#define pb push_back
//#define ivorysi
#define MAXN 300005
using namespace std;
typedef long long int64;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;char c = getchar();T f = 1;
    while(c < '0' || c > '9') {
    	if(c == '-') f = -1;
    	c = getchar();
    }
    while(c >= '0' && c <= '9') {
    	res = res * 10 + c - '0';
    	c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
    	out(x / 10);
    }
    putchar('0' + x % 10);
}
const int MOD = 1000000007;
int dp[MAXN][3][2][2],sum[MAXN],ans,N;
char s[MAXN];
int inc(int a,int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
    return 1LL * a * b % MOD;
}
void update(int &x,int y) {
    x = inc(x,y);
}
int fpow(int x,int c) {
    int res = 1,t = x;
    while(c) {
        if(c & 1) res = mul(res,t);
        t = mul(t,t);
        c >>= 1;
    }
    return res;
}
void Solve() {
    scanf("%s",s + 1);
    N = strlen(s + 1);
    for(int i = N ; i >= 1 ; --i) {
        sum[i] = sum[i + 1] + (s[i] == '?');
    }
    dp[0][0][0][0] = 1;
    for(int i = 1 ; i <= N ; ++i) {
        int t = 0;

        for(int j = 0 ; j <= 2 ; ++j) {
            for(int h = 0 ; h <= 1 ; ++h) {
                for(int k = 0 ; k <= 1 ; ++k) {
                    if(!dp[i - 1][j][h][k]) continue;
                    if(s[i] == '0' || s[i] == '?') {
                        if(k) update(dp[i][1][h][0],dp[i - 1][j][h][k]);
                        else {
                            if(j == 1) update(dp[i][2][h][0],dp[i - 1][j][h][k]);
                            else update(dp[i][1][h][0],dp[i - 1][j][h][k]);
                        }
                    }
                    if(s[i] == '1' || s[i] == '?') {
                        if(k) {
                            if(h) update(t,dp[i - 1][j][h][k]);
                            else update(dp[i][0][h + 1][0],dp[i - 1][j][h][k]);
                        }
                        else {
                            if(j == 1) update(dp[i][0][h][1],dp[i - 1][j][h][k]);
                            if(j == 2) update(dp[i][1][h][0],dp[i - 1][j][h][k]);
                            if(j == 0) {
                                if(h) update(t,dp[i - 1][j][h][k]);
                                else update(dp[i][0][h + 1][0],dp[i - 1][j][h][k]);
                            }
                        }
                    }
                }
            }
        }
        update(ans,mul(t,fpow(2,sum[i + 1])));
    }
    update(ans,inc(dp[N][0][1][1],dp[N][0][1][0]));
    out(ans);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
