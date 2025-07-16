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
void Debug() {cerr << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){
	cerr<<arg<<" ";Debug(rest...);}
template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {
	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}
template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){
	out<<"("<<v.first<<", "<<v.second<<")";return out;}
const int MAX_N = 500010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
mt19937 rng; //use it by rng() % mod, shuffle(all(vec), rng)
///////////////////////////////////////////////////////////////////////////////////////////////////

int N, X;
ll B[MAX_N], L[MAX_N], R[MAX_N];
int idx[MAX_N];
int fid[MAX_N];
ll RS[MAX_N], LS[MAX_N];

bool ok(ll m) {
	int q = m / X;
	int r = m % X;
	rep(i, 0, N) {
		ll tmp = 0;
		if(r == 0) {
			tmp += RS[q];
			tmp += LS[N] - LS[q];
		}
		else {
			if(B[i] > r) tmp += L[i] * (r - B[i]);
			else tmp += R[i] * (r - B[i]);

			if(fid[i] < q) {
				tmp -= R[i] * (X - B[i]);
				tmp += RS[q + 1];
				tmp += LS[N] - LS[q + 1];
			}
			else {
				tmp -= -L[i] * B[i];
				tmp += RS[q];
				tmp += LS[N] - LS[q];
			}
		}
		if(tmp >= 0) {
			return true;
		}
	}
	return false;
}

void solve() {
	cin >> N >> X;
	rep(i, 0, N) {
		cin >> B[i] >> L[i] >> R[i];
		idx[i] = i;
	}
	sort(idx, idx + N, [](int i, int j){
			return R[i] * (X - B[i]) + L[i] * B[i] > R[j] * (X - B[j]) + L[j] * B[j];
			});
	// rep(i, 0, N) {
	// 	debug(R[i] * (X - B[i]) - L[i] * B[i], B[i], L[i], R[i]);
	// }
	// debug(vi(idx, idx + N));
	rep(i, 0, N) {
		int at = idx[i];
		fid[at] = i;
		RS[i + 1] = RS[i] + R[at] * (X - B[at]);
		LS[i + 1] = LS[i] - L[at] * B[at];
	}

	ll lv = -1, rv = 1ll * N * X;
	while(rv - lv > 1) {
		ll m = (lv + rv) / 2;
		if(ok(m)) rv = m;
		else lv = m;
	}
	cout << rv << "\n";
}

uint32_t rd() {
	uint32_t res;
#ifdef __MINGW32__
	asm volatile("rdrand %0" :"=a"(res) ::"cc");
#else
	res = std::random_device()();
#endif
	return res;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
    cerr << fixed;
	cerr.precision(6);
	rng.seed(rd());
#ifdef LOCAL
	//freopen("in.txt", "wt", stdout); //for tester
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}

