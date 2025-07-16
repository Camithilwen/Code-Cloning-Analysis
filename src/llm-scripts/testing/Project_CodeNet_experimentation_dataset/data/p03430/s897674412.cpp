#include <bits/stdc++.h>
#define ADD(a, b) a = (a + ll(b)) % mod
#define MUL(a, b) a = (a * ll(b)) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define all(a) (a).begin(), (a).end()
#define sz(v) (int)(v).size()
#define pb push_back
#define sec second
#define fst first
#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> ppi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> mat;
typedef complex<double> comp;
void Debug() {cout << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){
	cout<<arg<<" ";Debug(rest...);}
template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {
	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}
template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){
	out<<"("<<v.first<<", "<<v.second<<")";return out;}
const int MAX_N = 200010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 29;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

int N, K;
int dp[310][310][310];
bool used[26];
string str;

int loop(int a, int b, int k) {
	if(k < 0) return -inf;
	else if(a > b + 1) return 1;
	else if(a == b + 1) return 0;
	else if(a == b) return 1;
	else if(dp[a][b][k] != -1) return dp[a][b][k];
	else {
		int res = 1;
		if(str[a] == str[b]) {
			MAX(res, loop(a + 1, b - 1, k) + 2);
		}
		else {
			MAX(res, loop(a + 1, b, k));
			MAX(res, loop(a, b - 1, k));
			MAX(res, loop(a + 1, b - 1, k - 1) + 2);
			for(int i = a; i < b; i++) {
				if(str[i] == str[b]) {
					MAX(res, loop(i + 1, b - 2, k - 1) + 2);
					break;
				}
			}
			for(int i = b; i > a; i--) {
				if(str[i] == str[a]) {
					MAX(res, loop(a + 2, i - 1, k - 1) + 2);
					break;
				}
			}
		}
		return dp[a][b][k] = res;
	}
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> str >> K;
	N = sz(str);
	cout << loop(0, N - 1, K) << "\n";
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
	srand((unsigned int)time(NULL));
#ifdef LOCAL
	//freopen("in.txt", "wt", stdout); //for tester
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

