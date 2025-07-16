#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define int long long
typedef long double ld;

const ld PI = acos(-1);

struct Point {
	int x, y;

	Point() {}

	Point(int x_, int y_) {
		x = x_;
		y = y_;
	}

	Point operator-(const Point &other) const {
		return Point(x - other.x, y - other.y);
	}

	bool operator<(const Point &other) const {
		return make_pair(x, y) < make_pair(other.x, other.y);
	}

	int operator*(const Point &other) const {
		return x * other.y - y * other.x;
	}

	int operator%(const Point &other) const {
		return x * other.x + y * other.y;
	}

	int dist(const Point &other) const {
		int dx = x - other.x;
		int dy = y - other.y;
		return dx * dx + dy * dy;
	}
};

ld ag(const Point &a, const Point &b, const Point &c) {
	Point f = (a - b);
	Point s = (c - b);
	ld ans = atan2(f * s, f % s);
	if (ans < 0) ans += PI;
	return ans;
}

vector<Point> convex_hull(vector<Point> a) {
	int mn = min_element(a.begin(), a.end()) - a.begin();
	Point to = a[mn];
	a.erase(a.begin() + mn);
	auto cmp = [&](const Point &f, const Point &s) {
		Point ff = (f - to);
		Point ss = (s - to);
		if (ff * ss != 0) {
			return ff * ss > 0;
		} else {
			return to.dist(f) < to.dist(s);
		}
	};
	auto ok_ang = [&](const Point &f, const Point &s, const Point &t) {
		Point ff = (s - f);
		Point ss = (t - s);
		return ff * ss > 0;
	};
	sort(a.begin(), a.end(), cmp); 
	vector<Point> st = {to};
	for (auto t : a) {
		while (st.size() > 1 && !ok_ang(st.rbegin()[1], st.rbegin()[0], t)) {
			st.pop_back();
		}
		st.push_back(t);
	}
	return st;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	int n;
	cin >> n;
	vector<Point> a(n);
	vector<ld> ans(n);
	map<Point, int> ind;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		ind[a[i]] = i;
	}
	a = convex_hull(a);
	n = (int)a.size();
	for (int i = 0; i < n; i++) {
		ld c = ag(a[(i - 1 + n) % n], a[i], a[(i + 1) % n]);
		if (n == 2) c = PI;
		ans[ind[a[i]]] = c / (2 * PI);
	}
	cout << fixed << setprecision(16);
	for (auto t : ans) {
		cout << t << '\n';
	}
}
