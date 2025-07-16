#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

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
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    ll H, W;
    cin >> H >> W;
    mat A(H, vec(W, 0));
    REP(i,0,H) {
        REP(j,0,W) {
            cin >> A[i][j];
            A[i][j] %= 2;
        }
    }

    mat Z;
    REP(i,0,H) {
        bool f = false;
        REP(j,0,W-1) {
            vec z = {i+1, j+1, i+1, j+2};
            if(A[i][j] == 1) {
                if(!f) {
                    A[i][j] = 0;
                    f = true;
                }
                else {
                    A[i][j] = 0;
                    f = false;
                }
            }
            if(f) Z.pb(z);
        }
        if(f) A[i][W-1] = 1 - A[i][W-1];
    }

    bool f = false;
    REP(i,0,H-1) {
        vec z = {i+1, W, i+2, W};
        if(A[i][W-1] == 1) {
            if(!f) {
                A[i][W-1] = 0;
                f = true;
            }
            else {
                A[i][W-1] = 0;
                f = false;
            }
        }
        if(f) Z.pb(z);
    }
    if(f) A[H-1][W-1] = 1 - A[H-1][W-1];

    PR(SZ(Z));
    REP(i,0,SZ(Z)) {
        PS(Z[i][0]); PS(Z[i][1]); PS(Z[i][2]); PR(Z[i][3]);
    }

    return 0;
}

/*



*/