#include <bits/stdc++.h>

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
 
#define F first
#define S second
#define EB emplace_back
#define PB push_back
#define ld long double
#define lb lower_bound
#define ub upper_bound
#define ar array
#define sz(x) (int)x.size()
#define bit(x) __builtin_popcount(x)
#define all(x) (x).begin(), (x).end()
#define FOR(c,l,r) for(int c=(l);c<=(r);c++)
 
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
 
using ll = long long;
//#define int ll
 
const int N = 2e6 + 7;
const int MOD = 1e9 + 7;
const int inf = 2e9 + 7;
const int  dx[]  = {-1,   0,   1,   0,  1, -1, -1,  1};
const int  dy[]  = { 0,   1,   0,  -1,  1, -1,  1, -1};
const char dt[] = {'U', 'R', 'D', 'L'};

map <int, int> mp;

int ok(int n) {
	while (n) {
		if (mp[n % 10]) return false;
		n /= 10;
	} return true;
}
void solve() {	
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i ++) {
		int x;
		cin >> x;
		mp[x] = 1;
 	}
	while (!ok(n)) {
		n ++;
	}
	cout << n;	
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
   	//cin >> tt;
    while (tt --){
        solve();
        cout << '\n';
    }
}

