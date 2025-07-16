#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>
#include <cstdio>
#include <list>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 1e9 + 7;
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> PLL;
typedef pair<LD, LL> PDL;
typedef pair<LD, LD> PDD;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
//typedef boost::multiprecision::cpp_int bigint;

template<class T>
void in(T& x) {
	cin >> x;
}

template<class T1, class T2>
void in(pair<T1, T2>& p) {
	in(p.first);
	in(p.second);
}

template<class T>
void in(vector<T>& v, LL st = -1, LL en = -1) {
	if (st == -1) {
		st = 0;
		en = v.size() - 1;
	}
	for (LL n = st; n <= en; n++) {
		in(v[n]);
	}
}

VLL mod(VLL& base, LL p) {
	LL N = base.size();
	if (p == 0) {
		VLL res(N);
		for (LL n = 0; n < N; n++)res[n] = n;
		return res;
	}
	if (p == 1)return base;
	VLL ret = mod(base, p / 2);
	VLL res(N);
	for (LL n = 0; n < N; n++) {
		res[n] = ret[ret[n]];
	}
	if (p % 2 == 0)return res;
	for (LL n = 0; n < N; n++) {
		ret[n] = res[base[n]];
	}
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	LL N, K,M;
	cin >> N;
	VLL X(N);
	in(X);
	VLL DX(N - 1);
	for (LL n = 0; n < N - 1; n++) {
		DX[n] = X[n + 1] - X[n];
	}
	cin >> M >> K;
	VLL A(M);
	in(A);
	VLL P(N - 1);
	for (LL n = 0; n < N-1; n++) {
		P[n] = n;
	}
	for (LL m = 0; m < M; m++) {
		LL n = A[m] - 1;
		swap(P[n - 1], P[n]);
	}
	P = mod(P, K);
	VLL res(N);
	res[0] = X[0];
	for (LL n = 1; n < N; n++) {
		res[n] = res[n - 1] + DX[P[n-1]];
	}
	for (LL n = 0; n < N; n++) {
		cout << res[n] << "\n";
	}
	return 0;
}
