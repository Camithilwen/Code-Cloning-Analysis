/*

This Submission is to determine how many 120/240 min const. delivery point there are.

//info
120 req. steps <= 5
*/
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
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 1000000007
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)

unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
//do gift-wrapping method
#define double long double
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
	double kaku = acos(min((double)1.0, max((double)-1.0, cosine)));
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
		double now_length = 0;
		int starter = ans[ans.size() - 1];
		for (int i = 0; i < a.size(); ++i) {
			if (i != starter) {
				double goa = angles(ba, a[i] - a[starter]);
				if (goa - now_min >= eps||(abs(goa - now_min) <= eps&&(abs(a[i] - a[starter]) - now_length) >= eps)) {
					now_min = goa;
					now_go = i;
					now_length = abs(a[i] - a[starter]);
				}
			}
		}
		if (now_go == ans[0]) break;
		ans.push_back(now_go);
		ba = complex<double>(a[now_go] - a[starter]);
	}
	return ans;
}
double ans[2000] = {};
#undef double
int main() {
#define double long double
	int n;
	cin >> n;
	vector<complex<double>> inputs;
	REP(i, n) {
		double x, y;
		cin >> x >> y;
		inputs.push_back(complex<double>(x, y));
	}
	vector<int> hoge;
	if (n == 2) {
		hoge.push_back(0);
		hoge.push_back(1);
	}
	else {
		hoge = convex_hull(inputs);
	}
	hoge.push_back(hoge[0]);
	hoge.push_back(hoge[1]);
	for (int i = 1; i < hoge.size() - 1; ++i) {
		complex<double> A = inputs[hoge[i]] - inputs[hoge[i - 1]];
		complex<double> B = inputs[hoge[i + 1]] - inputs[hoge[i]];
		complex<double> C = complex<double>(A.imag() * -1.0, A.real());
		complex<double> D = complex<double>(B.imag() * -1.0, B.real());
		ans[hoge[i]] = angles(D,C) / (2.0 * Ma_PI);
	}
	cout << fixed << setprecision(50);
	REP(i, n) {
		cout << ans[i] << endl;
	}
}