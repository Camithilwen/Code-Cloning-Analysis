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

struct P {
	double x, y; int num;
	P() {}
	P(double x, double y, int num) : x(x), y(y), num(num) {
	}
	P operator+(P p) { return P(x + p.x, y + p.y, 0); }
	P operator-(P p) { return P(x - p.x, y - p.y, 0); }
	double det(const P& p) { return x * p.y - y * p.x; }
	double norm() {
		return sqrt(x * x + y * y);
	}
	bool operator<(const P& p) { return y != p.y ? y < p.y : x < p.x; }
	friend ostream& operator<<(ostream& out, const P& p) {
		out << "(" << p.x << ", " << p.y << ")"; return out;
	}
};


vector<P> convex_hull(vector<P>& ps) {
	int n = sz(ps);
	sort(all(ps));
	int k = 0;
	vector<P> qs(n * 2);
	rep(i, 0, n) {
		while(k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= -eps) k--;
		qs[k++] = ps[i];
	}

	for(int i = n - 2, t = k; i >= 0; i--) {
		while(k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= -eps) k--;
		qs[k++] = ps[i];
	}
	qs.resize(k - 1);
	return qs;
}

int N;
double ans[110];

void solve() {
	cin >> N;
	vector<P> ps;
	rep(i, 0, N) {
		int a, b;
		cin >> a >> b;
		ps.pb(P{double(a), double(b), i});
	}
	if(N == 2) {
		cout << "0.5\n0.5\n";
		return;
	}
	auto qs = convex_hull(ps);
	int n = sz(qs);
	rep(i, 0, n) {
		P p = qs[i];
		double angle = 1.0;
		rep(j, 0, n) {
			rep(k, 0, n) {
				if(i == j || j == k || k == i) continue;
				P p1 = qs[j];
				P p2 = qs[k];
				p1 = p1 - p; p2 = p2 - p;
				double tmp = (p1.x * p2.x + p1.y * p2.y) / (p1.norm() * p2.norm());
				// debug(i, j, k, tmp, acos(tmp));
				MIN(angle, (PI - acos(tmp)) / (2 * PI));
			}
		}
		ans[qs[i].num] = angle;
	}
	rep(i, 0, N) {
		cout << ans[i] << "\n";
	}
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

