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
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    S += "*";
    vec L(Q), R(Q);
    REP(i,0,Q) {
        cin >> L[i] >> R[i];
    }

    vec P(N+1, 0);
    ll c = 0, i = 0;
    while(i < N-1) {
        if(S[i] == 'A' && S[i+1] == 'C') {
            P[i+1] = c;
            P[i+2] = c+1;
            ++c;
            i += 2;
        }
        else {
            P[i+1] = c;
            ++i;
        }
    }
    P[N] = c;
    
    REP(i,0,Q) {
        PR(P[R[i]]-P[L[i]]);
    }
    
    
    return 0;
}

/*



*/