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
    ll N;
    cin >> N;
    vec V(N+1);
    REP(i,1,N+1) cin >> V[i];

    vector<pll> od(100001, {0, 0}), ev(100001, {0, 0});
    ll x = V[1];
    bool f = false;
    REP(i,1,N/2+1) {
        ++od[V[i*2-1]].first;
        ++ev[V[i*2]].first;
        od[V[i*2-1]].second = V[i*2-1];
        ev[V[i*2]].second = V[i*2]; 
        if(x != V[i]) f = true;
    }

    if(f) {
        DESC(od);
        DESC(ev); 
        ll mo = od[0].first, me = ev[0].first;
        if(od[0] == ev[0]) {
            if(od[1].first < ev[1].first) me = ev[1].first;
            else mo = od[1].first;
        } 
        PR(N-mo-me);
    }
    else PR(N/2);

    return 0;
}

/*



*/