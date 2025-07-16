#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>
 
#include<deque>
#define pi 3.141592653589793238
#include<chrono>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
 
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
 
 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int N = 9e5 + 1;
ll fac[N];
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;

    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;


        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll modi(ll a, ll m)
{
    return power(a, m - 2, m);

}
ll nCr(ll n, ll r, ll p)
{

    if (r == 0)
        return 1;
    fac[0] = 1;
    
    return (fac[n] * modi(fac[r], p) % p *
        modi(fac[n - r], p) % p) % p;
} 
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    fac[0] = 1;
    for (i = 1; i <= 9e5; i++){
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    //cin >> T;
    while (T--) {
        ll h, w, a, b;
        cin >> h >> w >> a >> b;
        ll ans = 0;
        ll ways = 1;
        for(i = 1; i <= h - a; i++){
            ll v1, v2;
            ll m, n;
            m = i, n = b;
            v1 = nCr(m + n - 2, n - 1, MOD);
            ways = v1;
            m = h - i + 1, n = w - b;
            v2 = nCr(m + n - 2 , n - 1, MOD);
            ans += v1 * v2;
            ans %= MOD;
        }
        
        cout << ans;
    }
    return 0;
}