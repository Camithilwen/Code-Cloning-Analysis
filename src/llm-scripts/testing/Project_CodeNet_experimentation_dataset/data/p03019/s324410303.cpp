//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
 
//#include <x86intrin.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <bitset> 
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
//#include <ordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
//using namespace __gnu_pbds;
using namespace std;
 
//template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
     
#define F first
#define S second           
#define lb lower_bound               
#define ub upper_bound
#define pb push_back
#define pf push_front    
#define ppb pop_back
#define mp make_pair                                     
#define bpp __builtin_popcountll                                                                                        
#define sqr(x) ((x) * (x)) 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define in insert
#define ppf pop_front
#define endl '\n'
#define int long long
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
const int mod = (int)1e9 + 7;
const int N = (int)3e5 + 123;
const ll inf = (ll)1e18 + 1;
 
const double pi = acos (-1.0);
const double eps = 1e-9;                  
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

int n, x, now;

struct e {
   int l, r, b;
}a[N];

bool cmp (e a, e b) {                                                      
   return (a.r * (x - a.b) + a.l * a.b) > (b.r * (x - b.b) + b.l * b.b);
}

inline bool check (int h) {
   now = h;
   int ans = 0;
   int res = -inf;
   bool ok = 0;
   for (int i = 1; i <= n; i ++) {
      if (h >= x) {
         h -= x;
         ans += (x - a[i].b) * a[i].r;
      }
      else {
         int sum = 0;
         ok = 1;
         for (int j = i; j <= n; j ++) {
            sum -= a[j].l * a[j].b;
         }
         for (int j = i; j <= n; j ++) {
            sum += a[j].l * a[j].b;
            res = max (res, ans + sum + (h - a[j].b) * a[j].l);
            res = max (res, ans + sum + (h - a[j].b) * a[j].r);
            sum -= a[j].l * a[j].b;
         }                    
         for (int j = 1; j < i; j ++) {
            int in = ans - (x - a[j].b) * a[j].r + sum + a[i].l * a[i].b;
            if (h < a[j].b) in += (h - a[j].b) * a[j].l;
            else in += (h - a[j].b) * a[j].r;
            in += (x - a[i].b) * a[i].r;
            res = max (res, in);
         }         
         break;
      }
   }
   if (!ok) res = ans;  
   return (res >= 0);
}

inline void boost () {
   ios_base :: sync_with_stdio (0);
   cin.tie (0), cout.tie (0);
}
 
inline void Solve () {
   cin >> n >> x;
   for (int i = 1; i <= n; i ++) cin >> a[i].b >> a[i].l >> a[i].r;    
   sort (a + 1, a + n + 1, &cmp);
   int l = 0, r = inf, pos = -1;
   while (l <= r) {
      int mid = l + r >> 1;
      if (check (mid)) r = mid - 1, pos = mid;
      else l = mid + 1;
   }
   cout << pos;
}               
 
signed main () {                                       
   #ifdef QWERTY
      freopen("input", "r", stdin);
   #endif
// freopen (".in", "r", stdin);    
// freopen (".out", "w", stdout);              
   boost ();
   int tt = 1;
   //cin >> tt;   
   while (tt --) {
      Solve ();
   }                                               
   return 0;      
}                   