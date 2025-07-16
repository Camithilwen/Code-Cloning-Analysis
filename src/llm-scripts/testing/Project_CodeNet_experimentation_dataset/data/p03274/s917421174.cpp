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
    ll N, K;
    cin >> N >> K;
    vec X(N);
    REP(i,0,N) cin >> X[i];

    ll p = N;
    REP(i,0,N) {
        if(X[i] >= 0) {
            if(X[i] == 0) {
                X.erase(X.begin() + i);
                --K;
            }
            p = i;
            break;
        }
    }

    ll left, right; 
    if(p < K) {
        left = 0;
        right = K - 1;
    }
    else {
        left = p - K;
        right = p - 1;
    }

    ll m = INF;
    if(K == 0) m = 0;
    else {
        while(left <= p && right < N) {
            ll t;
            if(X[left] < 0 && X[right] < 0) t = -X[left];
            else if(X[left] < 0) t = MIN(X[right]-2*X[left],X[right]*2-X[left]);
            else t = X[right];
            m = MIN(m,t);
            ++left;
            ++right;
        }
    }
    PR(m);

    return 0;
}

/*



*/