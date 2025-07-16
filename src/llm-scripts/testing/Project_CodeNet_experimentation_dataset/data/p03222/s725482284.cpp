#pragma GCC optimize(3 , "Ofast" , "inline")

#include <bits/stdc++.h>

#define rep(i , a , b) for(register int i=(a);i<=(b);i++)
#define per(i , a , b) for(register int i=(a);i>=(b);i--)


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> pi;

template<class T>
inline void read (T &x) {
    x = 0;
    int sign = 1;
    char c = getchar ();
    while (c < '0' || c > '9') {
        if ( c == '-' ) sign = - 1;
        c = getchar ();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar ();
    }
    x = x * sign;
}

const int maxn = 2e5 + 10;
const int inf = int (1e9);
const ll INF = ll (1e18);
const double PI = acos (- 1);
const int mod = 1e9+7;
const double eps = 1e-8;

ll dp[111][10];


int main () {
    int h,w,m;
    read (h);read (w);read (m);
    if(w==1) {
        puts ("1");
        return 0;
    }
    dp[0][0]=1;
    rep (i,1,h) {
        rep (j,0,(1<<w-1)-1) {
            bool ok=1;
            rep (k,0,w-3) {
                if((j&(1<<k))&&(j&(1<<k+1))) {
                    ok=0;
                    break;
                }
            }
            if(!ok) continue;
            rep (k,0,w-1) {
                if(k>=1&&(j&(1<<(k-1)))) {
                    dp[i][k]=(dp[i][k]+dp[i-1][k-1])%mod;
                }
                else if(k<w-1&&(j&(1<<k))) {
                    dp[i][k]=(dp[i][k]+dp[i-1][k+1])%mod;
                }
                else dp[i][k]=(dp[i][k]+dp[i-1][k])%mod;
            }
        }
    }
    cout<<dp[h][m-1]<<endl;
    return 0;
}
