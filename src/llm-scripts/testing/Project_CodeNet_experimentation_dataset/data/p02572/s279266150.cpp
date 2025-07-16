
#include<bits/stdc++.h>


using namespace std;

using ll   = long long;
using ii   = pair   < int , int >;
using i3   = pair   < int , ii  >;
using li   = pair   < ll  , int >;
using lii  = pair   < ll  , ii  >;
using pll  = pair   < ll  , ll  >;
using vi   = vector < int       >;
using vl   = vector < ll        >;
using vii  = vector < ii        >;
using vli  = vector < li        >;
using vpll = vector < pll       >;
using vi3  = vector < i3        >;
using vlii = vector < lii       >;


const int N = 2e5 + 5;
const ll INF = 1e17 + 7 , mod = 1e9 + 7;
const double eps = 1e-9 , PI = acos(-1);



int n;

ll mul(ll a , ll b) {
    return a%mod * (b%mod) % mod;
}

ll sum(ll a , ll b) {
    return (a%mod + b%mod) % mod;
}

ll a[N];
ll suff[N];

void solve(int testCase){

    scanf("%d" , &n);

    for(int i = 0 ; i < n ; i ++) {
            scanf("%lld" , &a[i]);
    }

    suff[n] = 0;

    for(int i = n - 1 ; i >= 0 ; i --) {
            suff[i] = sum(suff[i + 1] , a[i]);
    }

    ll ans = 0ll;
    for(int i = 0 ; i < n ; i ++) {
            ans = sum(ans , mul(a[i] , suff[i + 1]));
    }

    printf("%lld\n" , ans);
}

main(){

    int t = 1;
    // scanf("%d" , &t);

    for(int testCase = 1 ; testCase <= t ; testCase ++){
            solve(testCase);
    }

    return 0;
}
