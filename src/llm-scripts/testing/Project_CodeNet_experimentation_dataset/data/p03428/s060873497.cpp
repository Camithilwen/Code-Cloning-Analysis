#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long ll;

double cross(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
	pair<double, double> u = { a.first - c.first, a.second - c.second };
	pair<double, double> v = { a.first - b.first ,a.second - b.second };
	return u.first*v.second - u.second*v.first;
}

double abs(pair<double, double> a) {
	return sqrt(a.first*a.first + a.second*a.second);
}

int main() {
	int n; cin >> n;
	if (n == 2) {
		cout << 0.5 << endl;
		cout << 0.5 << endl;
		return 0;
	}
	vector<pair<pair<double, double>, int>> pi(n);
	for (int i = 0; i < n; i++) cin >> pi[i].first.first >> pi[i].first.second, pi[i].second = i;
	sort(pi.begin(), pi.end());
	double lm = 1e9; int idx = 0;
	vector<pair<pair<double, double>, int>> chi;
	bool used[103] = {};
	chi.push_back(pi[0]);
	used[idx] = true;
	for (int iter = 1; iter < n; iter++) {
		const auto &pr = chi.back().first;
		for (int i = 0; i < n; i++) {
			if (used[i]) continue;
			const auto &p = pi[i].first;
			int sgn = 0;
			bool flag = true;
			for (int j = 0; j < n; j++) {
				if (j == i) continue;
				if (p.first == pr.first && p.second == pr.second) continue;
				int s = cross(pr, p, pi[j].first) > 0 ? 1 : -1;
				flag &= sgn == 0 || s == sgn;
				sgn = s;
			}
			if (flag) {
				if (chi.size() >= 2) {
					const auto &pb = chi[chi.size() - 2].first;
					double s = (pr.first - p.first)*(pb.second - p.second);
					s -= (pb.first - p.first)*(pr.second - p.second);
					s /= 2.;
					s = abs(s);
					if (s < 1e-8) {
						chi.pop_back();
					}
				}
				chi.push_back(pi[i]);
				used[i] = true;
				break;
			}
		}
	}
	if (chi.size() >= 3) {
		const auto &pr = chi.back().first;
		const auto &pb = chi[chi.size() - 2].first;
		const auto &p = chi[0].first;
		double s = (pr.first - p.first)*(pb.second - p.second);
		s -= (pb.first - p.first)*(pr.second - p.second);
		s /= 2.;
		s = abs(s);
		if (s < 1e-8) {
			chi.pop_back();
		}
	}
	vector<double> ans(n);
	int m = chi.size();
	if (m >= 3) {
		for (int i = 0; i < m; i++) {
			const auto &pr = chi[(i - 1 + m) % m].first;
			const auto &pn = chi[(i + 1) % m].first;
			const auto &p = chi[i].first;
			pair<double, double> u = { p.first - pr.first, p.second - pr.second };
			pair<double, double> v = { p.first - pn.first, p.second - pn.second };
			double ang = acos((u.first*v.first + u.second*v.second) / abs(u) / abs(v));
			double r = acos(-1) - ang;
			ans[chi[i].second] = r / (2 * acos(-1));
		}
	}
	else {
		for (int i = 0; i < m; i++) {
			ans[chi[i].second] = 0.5;
		}
	}
	for (int i = 0; i < n; i++) printf("%.15f\n", ans[i]);
	int b = 2 * 0.;
	return 0;
}
