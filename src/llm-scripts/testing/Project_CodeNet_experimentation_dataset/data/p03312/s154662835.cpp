#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i=n; i<(int)m; i++)
#define ROF(i,n,m) for(int i=n; i>(int)m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ri(a) scanf("%d",&a)
#define rii(a,b) ri(a),ri(b)
#define riii(a,b,c) rii(a,b),ri(c)
#define lri(a) scanf("%lld",&a)
#define lrii(a,b) lri(a),lri(b)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define debug true
#define dprintf debug && printf

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

ll pref[MAXN];
int n;

ll sum(int l, int r){
    if(l > r) return 0;
    return pref[r] - (l == 0 ? 0 : pref[l-1]);
}

ll dif(int l, int r, int m){
    return abs(sum(l, m-1) - sum(m, r));
}

void mxze(ll &a, ll b){
    a = max(a,b);
}
void mnze(ll &a, ll b){
    a = min(a,b);
}

ll result(int m1, int m, int m2){
    ll mx = sum(0,m1-1);
    mxze(mx, sum(m1,m-1));
    mxze(mx, sum(m,m2-1));
    mxze(mx, sum(m2,n-1));

    ll mn = sum(0,m1-1);
    mnze(mn, sum(m1,m-1));
    mnze(mn, sum(m,m2-1));
    mnze(mn, sum(m2,n-1));

    return mx - mn;
}

bool check(int l, int r, int m){
    return dif(l, r, m) > dif(l,r,m+1);
}

int findBest(int l, int r){
    int lo = l + 1, hi = r;
    while(lo < hi){
        int mid = (lo + hi)>>1;
        if(check(l, r, mid)) lo = mid + 1;
        else hi = mid;
    }
    return hi;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    ri(n);
    FOR(i,0,n) lri(pref[i]);
    FOR(i,1,n) pref[i] += pref[i-1];

    ll ans = INFLL;
    FOR(m,2,n-1){
        mnze(ans, result(findBest(0,m-1), m, findBest(m, n-1)));
    }

    printf("%lld\n", ans);

    return 0;
}
