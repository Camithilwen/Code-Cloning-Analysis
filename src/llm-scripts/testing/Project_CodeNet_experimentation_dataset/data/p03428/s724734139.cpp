#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 1000000007;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ld = double;
using vec = complex<ld>;
#define x real()
#define y imag()
ld dot(vec a, vec b) {
	return (conj(a)*b).x;
}
ld cross(vec a, vec b) {
	return (conj(a)*b).y;
}
istream& operator>>(istream& in, vec &v) {
	ld a, b;
	in >> a >> b;
	v = vec(a, b);
	return in;
}
bool cw(vector<pair<vec, int>> &hull, vec &v) {
	int n = hull.size();
	if(n < 2) return true;
	return cross(hull[n-1].first-hull[n-2].first, v-hull[n-1].first)<=0;
}
ld ans[100100];
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<vec, int>> v;
	v.resize(n);
	int _T = 0;
	for(auto &i : v) {
		cin >> i.first;
		i.second = ++_T;
	}
	for(auto &i : v) {
		if(i.first.x < v.back().first.x || (i.first.x == v.back().first.x&&i.first.y<v.back().first.y))
			swap(v.back(), i);
	}
	vector<pair<vec, int>> hull {v.back()};
	v.pop_back();
	sort(all(v), [&](const pair<vec, int> &a, const pair<vec, int> &b) {
		if(fabs(cross(a.first-hull[0].first, b.first-hull[0].first))<1e-9)
			return abs(a.first-hull[0].first) < abs(b.first-hull[0].first);
		return cross(a.first-hull[0].first, b.first-hull[0].first) < 0;
	});
	for(auto i : v) {
		while(!cw(hull, i.first)) hull.pop_back();
		hull.pb(i);
	}
	for(int i = 0; i < hull.size(); i++) {
		vec l = (i?hull[i-1]:hull.back()).first;
		vec r = (i+1<hull.size()?hull[i+1]:hull[0]).first;
//		cout << hull[i].first << "\n";
//		cout << hull[i].first << " " << l << " " << r << "\n";
		l-=hull[i].first,	r-=hull[i].first;
		ld angle = M_PI - acos(((dot(l, r)/abs(l))/abs(r)));
//		cout << hull[i].first << " " << l << " " << r << "\n";
//		cout << dot(l, r) << "\n";
		ans[hull[i].second] = angle/(2*M_PI);
	}
	cout << fixed << setprecision(15);
	for(int i = 1; i <=n; i++) cout << ans[i] << "\n";
}

