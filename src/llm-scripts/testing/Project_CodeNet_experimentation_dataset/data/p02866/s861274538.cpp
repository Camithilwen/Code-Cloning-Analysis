#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 998244353
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


ll modpow(ll a, ll n, ll m)
{
    if(n == 0) return 1;
    ll t = modpow(a, n >> 1, m);
    t = t * t % m;
    if(n & 1) t = t * a % m;
    return t; 
}

int main()
{
    ll N;
    cin >> N;
    vec D(N);
    REP(i,0,N) cin >> D[i];
    
    vec A(N, 0);
    if(D[0] != 0) PR(0);
    else {
        ll m = 0;
        REP(i,0,N) {
            ++A[D[i]];
            m = MAX(m,D[i]);
        }
        if(A[0] > 1) PR(0);
        else {
            ll cnt = 1;
            REP(i,1,m+1) {
                cnt = (cnt * modpow(A[i-1], A[i], MOD)) % MOD;
            }
            PR(cnt);
        }
    }

    return 0;
}

/*



*/