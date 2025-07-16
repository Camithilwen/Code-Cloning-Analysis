#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
double dot(complex<double> a, complex<double> b) {
	return a.real() * b.real() + a.imag() * b.imag();
}
double gyaku_dot(complex<double> a, complex<double> b) {
	return a.real() * b.imag() - a.imag() * b.real();
}
double leng(complex<double> a) {
	return sqrt(a.real() * a.real() + a.imag() * a.imag());
}
double angles(complex<double> a, complex<double> b) {
	double cosine = dot(a, b) / (leng(a) * leng(b));
	double sine = gyaku_dot(a, b) / (leng(a) * leng(b));
	double kaku = acos(cosine);
	if (sine <= 0) {
		kaku = 2 * Ma_PI - kaku;
	}
	return kaku;
}
vector<int> convex_hull(vector<complex<double>> a) {
	vector<int> ans;
	double now_minnest = a[0].real();
	int now_itr = 0;
	REP(i, a.size()) {
		if (now_minnest > a[i].real()) {
			now_minnest = a[i].real();
			now_itr = i;
		}
	}
	ans.push_back(now_itr);
	complex<double> ba(0, 1);
	while (true) {
		int now_go = 0;
		double now_min = 0;
		int starter = ans[ans.size() - 1];
		for (int i = 0; i < a.size(); ++i) {
			if (i != starter) {
				double goa = angles(ba, a[i] - a[starter]);
				if (goa > now_min) {
					now_min = goa;
					now_go = i;
				}
			}
		}
		if (now_go == ans[0]) break;
		ans.push_back(now_go);
		ba = complex<double>(a[now_go] - a[starter]);
	}
	return ans;
}
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
vector<tuple<long long, long long, long long, long long>> inputs;
long long required_costs[300000] = {};
long long winning_value[300000] = {};
long long n, x;
long long solve(long long now, long long border) {
	long long cost = winning_value[now] - required_costs[now];
	if (border < now) {
		cost -= x * get<3>(inputs[border]);
		cost += get<1>(inputs[border]) * get<3>(inputs[border]);
		cost -= get<1>(inputs[border]) * get<2>(inputs[border]);
	}
	return cost;
}
int main() {
	iostream::sync_with_stdio(false);
#define int long long
	cin >> n >> x;
	REP(i, n) {
		long long a, b, c;
		cin >> a >> b >> c;
		inputs.push_back(make_tuple(c * (x - a) + b * a, a, b, c));
	}
	sort(inputs.begin(), inputs.end());
	reverse(inputs.begin(), inputs.end());
	long long costing = 0;
	REP(i, n) {
		costing += get<1>(inputs[i]) * get<2>(inputs[i]);
	}
	long long bobo = 0;
	REP(i, n + 1) {
		required_costs[i] = costing;
		winning_value[i] = bobo;
		if (i < n) {
			costing -= get<1>(inputs[i]) * get<2>(inputs[i]);
			bobo += get<3>(inputs[i]) * (x - get<1>(inputs[i]));
		}
	}
	long long ans = LONG_INF;
	for (int i = 0; i < n; ++i) {
		long long bot = 0;
		long long top = n;
		while (top - bot > 1) {
			long long mid = (top + bot) / 2;
			if (solve(mid, i) <= 0) {
				bot = mid;
			}
			else {
				top = mid;
			}
		}
		long long bobo = solve(bot, i);
		bobo *= -1;
		long long pre_ans = bot * x;
		if (i < bot) {
			pre_ans -= x;
		}
		long long now = x + 1;
		now = (bobo + get<2>(inputs[i]) - 1) / get<2>(inputs[i]);
		if (now >= 0 && now <= x) {
			ans = min(ans, pre_ans + now);
		}
		bobo += (get<3>(inputs[i]) - get<2>(inputs[i])) * get<1>(inputs[i]);
		now = (bobo + get<3>(inputs[i]) - 1) / get<3>(inputs[i]);
		if (now >= 0 && now <= x) {
			ans = min(ans, pre_ans + now);
		}
	}
	ans = min(ans, x * n);
	cout << ans << endl;
}
