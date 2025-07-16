#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double dp[310][310][310];
ll n;

double calc(int x, int y, int z){
    double ret=0.0;
    if(0<=dp[x][y][z]) return dp[x][y][z];
    if(!x && !y && !z) return 0.0;
    if(0<x) ret += calc(x-1, y, z)*x;
    if(0<y) ret += calc(x+1, y-1, z)*y;
    if(0<z) ret += calc(x, y+1, z-1)*z;
    ret += n;
    ret *= 1.0/(x+y+z);
    return dp[x][y][z] = ret;
}

int main(){
    cin >> n;
    vector<ll> a(n);    
    ll c1=0, c2=0, c3=0;
    rep(i, n){
        ll x;   cin >> x;
        if(x==1) c1++;
        else if(x==2) c2++;
        else c3++;
    }
    memset(dp, -1, sizeof(dp));
    cout << fixed << setprecision(20) << calc(c1, c2, c3) << endl;
}
