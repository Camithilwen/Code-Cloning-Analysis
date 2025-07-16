#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define DEBUG_ARR(v,n) cout<<#v<<":";REP(i,n)cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true; }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T>
void DEBUG_DP(T* viewdp, int ilen, int jlen){
    REP(i,ilen){
        REP(j,jlen){
            if(viewdp[i][j] != -1)
                printf("[% 4d]", viewdp[i][j]);
            else
                printf("[    ]");
        }
        puts("");
    }
}
const int N=81;
const int C=6400;
const int K=C*2+1;
int h,w;
int a[N][N], b[N][N];
bitset<K> dp[N][N];
int ans = INT_MAX;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    REP(i,N){
        fill(a[i], a[i]+N, -1);
        fill(b[i], b[i]+N, -1);
    }

    cin>>h>>w;

    REP(i,h) REP(j,w) cin>>a[i][j];
    REP(i,h) REP(j,w) cin>>b[i][j];

    //int sx=0,sy=0, gx=w-1, gy=h-1;
    dp[0][0][abs(a[0][0]-b[0][0]) + 6400]=true;

    REP(i,h) REP(j,w){
        int ab =abs(a[i+1][j]-b[i+1][j]);

        dp[i+1][j] |= dp[i][j] << ab;
        dp[i+1][j] |= dp[i][j] >> ab;

        ab =abs(a[i][j+1]-b[i][j+1]);
        dp[i][j+1] |= dp[i][j] << ab;
        dp[i][j+1] |= dp[i][j] >> ab;
    }

    REP(i,K){
        if(dp[h-1][w-1][i]) chmin(ans, abs(6400-i));
    }

    cout << ans << endl;
    return 0;
}