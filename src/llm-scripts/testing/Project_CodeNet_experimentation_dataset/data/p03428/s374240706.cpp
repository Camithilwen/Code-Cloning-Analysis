#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-10;

template <typename T> void dump(T x) { cout << x << endl; }
void dumpf(ld x, int t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}

ll mod(ll a, ll b) {
	if (a > 0) return a % b;
	if (a % b == 0) return 0;
	ll x = -a / b + 1;
	a += x * b;
	return a % b;
}

// ll dx[4] = {1, 0, -1, 0};
// ll dy[4] = {0, 1, 0, -1};
// ll pas[5001][5002];

ld add(ld a, ld b) {
	if (abs(a + b) < EPS * (abs(a) + abs(b))) return 0;
	return a + b;
}

struct Point {
	ld x, y;
	int num;
	Point() {}
	Point(ld x, ld y) : x(x), y(y) {}
	Point(ld x, ld y, int n) : x(x), y(y), num(n) {}
	Point operator+(const Point &p) { return Point(add(x, p.x), add(y, p.y)); }
	Point operator-(const Point &p) {
		return Point(add(x, -p.x), add(y, -p.y));
	}
	bool operator==(const Point &p) { return x == p.x && y == p.y; }
	bool operator!=(const Point &p) { return *this == p; }
	bool operator<(const Point &p) {
		if (x != p.x)
			return x < p.x;
		else
			return y < p.y;
	}
	friend Point operator*(ld k, const Point &p) {
		return Point(k * p.x, k * p.y);
	}
	ld dot(const Point &p) { return add(x * p.x, y * p.y); }
	ld det(const Point &p) { return add(x * p.y, -y * p.x); }
};

vector<Point> convex_hull(vector<Point> p) {
	sort(p.begin(), p.end());
	int n = p.size();
	int k = 0;
	vector<Point> q(2 * n);
	for (int i = 0; i < n; i++) {
		while (k > 1 && (q[k - 1] - q[k - 2]).det(p[i] - q[k - 1]) <= 0) k--;
		q[k++] = p[i];
	}
	for (int i = n - 2, t = k; i >= 0; i--) {
		while (k > t && (q[k - 1] - q[k - 2]).det(p[i] - q[k - 1]) <= 0) k--;
		q[k++] = p[i];
	}
	q.resize(k - 1);
	return q;
}

ld dist(Point p1, Point p2) { return (p1 - p2).dot(p1 - p2); }
ld dif(Point p1, Point p2) { return sqrt(dist(p1, p2)); }

ld longestdist(vector<Point> t) {
	int n = t.size();
	ld M  = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) { M = max(M, dist(t[i], t[j])); }
	}
	return M;
}

int main() {
	IOS();
	ll n;
	cin >> n;
	vector<Point> p(n);
	vector<ld> ans(n, 0);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		p[i] = Point(x, y, i);
	}

	vector<Point> q = convex_hull(p);

	int m = q.size();
	for (int j = 0; j < m; j++) {
		ld costh = (q[mod(j - 1, m)] - q[j]).dot(q[mod(j + 1, m)] - q[j]);
		costh /= dif(q[mod(j - 1, m)], q[j]) * dif(q[mod(j + 1, m)], q[j]);
		if (abs(costh - 1) <= EPS) costh = 1.0;
		if (abs(costh + 1) <= EPS) costh = -1.0;
		ans[q[j].num] = (M_PI - acos(costh)) / (2 * M_PI);
	}
	for (int i = 0; i < n; i++) { dumpf(ans[i], 8); }
	return 0;
}