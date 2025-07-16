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
set<ll> s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    //cin >> T;
    while (T--) {
        ll calcy = 0;
        ll n, m;
        cin >> n >> m;
        vector<ll> x(n), y(m);
        for(i = 0; i < n; i++){
            cin >> x[i];
        }
        for(i = 0; i < m; i++){
            cin >> y[i];
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        vector<ll> dp(n + 1);
        for(i = 0; i < m; i++){
            calcy -= (m - 1 - i) * y[i];
            calcy += i * (y[i]);
            calcy %= MOD;
        }
        ll calcx = 0;
        for(i = 0; i < n; i++){
            calcx -= (n - 1 - i) * x[i];
            calcx += i * (x[i]);
            calcx %= MOD;
        }
        cout << calcy * calcx % MOD;
    }
    return 0;
}