///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<double, null_type, less_equal<double>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define int long long
typedef long long ll;
typedef double dd;
typedef long double ldd;
typedef pair <int, int> pii;
typedef pair <pii , int> ppii;
#define pb push_back
#define pf push_front
#define ppb pop_back()
#define ppf pop_front()
#define f first
#define s second
#define sz(x) (int)x.size()
#define smin(x , y) x = min(x , y)
#define smax(x , y) x = max(x , y)
#define mp make_pair
#define all(x) x.begin() , x.end()
#define debug(x) cerr<< #x << " = " << x << endl
#define ddebug(x, y) cerr<< #x << " = " << x  << ", " << #y << " = " << y << endl
#define uop(x, y) pii(min(x, y), max(x, y))
#define out return cout << "No" << endl, 0
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
const int mx = 6e3 + 10;
int n, m, fact[mx], inv[mx], C[mx][mx], M2[mx], M3[mx], p[mx];
int _pow(int a, int b){
	if(!b)
		return 1;
	return ((_pow((a * a) % m, b >> 1) * ((b & 1) ? a : 1)) % m);
}
void pre(){
	fact[0] = 1;
	for(int i = 1; i <= 3 * n; i++)
		fact[i] = (fact[i - 1] * i) % m;
	inv[3 * n] = _pow(fact[3 * n] , m - 2);
	for(int i = 3 * n - 1; ~i; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % m;
	for(int i = 0; i <= 3 * n; i++)
		for(int j = 0; j <= i; j++)
			C[i][j] = fact[i] * inv[j] % m * inv[i - j] % m;
	M2[0] = 1;
	for(int i = 2; i <= 3 * n; i += 2)
		M2[i] = M2[i - 2] * C[i][2] % m;
	M3[0] = 1;
	for(int i = 3; i <= 3 * n; i += 3)
		M3[i] = M3[i - 3] * C[i][3] % m;
	p[0] = 1;
	for(int i = 1; i <= 3 * n; i++)
		p[i] = p[i - 1] * 2 % m;
	return;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	pre();
	int ans = 0;
	for(int a = 0; a <= n; a++)
		for(int b = 0; b <= n; b++){
			int c = 3 * n - 3 * a - 2 * b;
			if(c < b)
				continue;
			int cnt = (C[3 * n][3 * a] * p[a] % m * M3[3 * a] % m * inv[a] % m) % m;
			cnt = cnt * (C[3 * n - 3 * a][2 * b] * M2[2 * b] % m * inv[b] % m) % m;
			ans = (ans + cnt) % m;
		}
	cout << ans << endl;
	return 0;
} 
