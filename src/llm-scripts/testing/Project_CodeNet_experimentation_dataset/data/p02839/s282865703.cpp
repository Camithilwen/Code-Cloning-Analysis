#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ASC(x) sort(ALL((x)))
#define DESC(x) sort(ALL((x)),greater<ll>())
#define REV(x) reverse(ALL((x)))
#define pb push_back

int main()
{
    ll H, W;
    cin >> H >> W;    
    mat A(H+1, vec(W+1, 0)), B(H+1, vec(W+1, 0));
    REP(i,1,H+1) REP(j,1,W+1) cin >> A[i][j];
    REP(i,1,H+1) REP(j,1,W+1) cin >> B[i][j];

    ll K = 160 * 80;
    bool dp[H+1][W+1][K+1];
    REP(i,0,H+1) {
        REP(j,0,W+1) {
            REP(k,0,K+1) dp[i][j][k] = false;
        }
    }
    dp[0][1][0] = true;
    dp[1][0][0] = true;

    ll d;
    REP(i,1,H+1) {
        REP(j,1,W+1) {
            REP(k,0,K+1) {
                d = abs(A[i][j] - B[i][j]);
                if(k + d <= K) {
                    dp[i][j][k+d] |= dp[i][j-1][k];
                    dp[i][j][k+d] |= dp[i-1][j][k];
                }
                if(abs(k - d) <= K) {
                    dp[i][j][abs(k-d)] |= dp[i][j-1][k];
                    dp[i][j][abs(k-d)] |= dp[i-1][j][k];
                }
            }
        }
    }

    REP(k,0,K) {
        if(dp[H][W][k]) {
            PR(k);
            break;
        }
    }


    return 0;
}

/*



*/