// copied by Nurstan Duisengaliev
// skatal
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 
 
#define ll long long
#define all(x) x.begin(), x.end()
#define in insert
#define mp make_pair
#define F first
#define S second
#define ppf pop_front
#define pb push_back
#define ppb pop_back
#define pf push_front
#define pii pair <int, int>
#define boost() ios_base::sync_with_stdio(0), cin.tie(0)
#define sz(x) (int)x.size()
 
using namespace std;
//using namespace __gnu_pbds;

//template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;                         

const int N = (int)5e5 + 123;
const int mod = (int)1e9 + 7;
const ll INF = (ll)1e18 + 7;
int n, a[N];
void solve () {
	cin >> n;
	n *= 2;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort (a + 1, a + n + 1);
	ll sum = 0;
	for (int i = 1; i <= n; i += 2) sum += a[i];
	cout << sum;
}   	
 
main () {
//	freopen (".in", "r", stdin);
//	freopen (".out", "w", stdout);
	boost ();
	int TT = 1;
//    cin >> TT;
	while (TT --) {
		solve ();
	}
	return 0;	
}