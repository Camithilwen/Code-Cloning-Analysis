//#pragma warning(disable:4996)
//#include <Windows.h>
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
#include <bitset>
//#include <stdio.h>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
typedef long long LL;
typedef long double LD;
//typedef boost::multiprecision::cpp_int bigint;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PI;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef unsigned long long ULL;
template<class T>
using pqueue = priority_queue<T, vector<T>, function<bool(T, T)>>;

template<class T>
inline void chmin(T& a, T b) {
	a = min(a, b);
}

template<class T>
inline void chmax(T& a, T b) {
	a = max(a, b);
}

void input();
void solve();

void daminput();
void naive();

void outputinput();

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	input();
	//daminput();
	solve();
	//naive();
	//outputinput();
	return 0;
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////

int N, Q;
VLL A;
VLL query;

void input() {
	cin >> N >> Q;
	A.resize(N);
	for (int n = 0; n < N; n++) {
		cin >> A[n];
	}
	query.resize(3 * Q);
	for (int q = 0; q < 3 * Q; q++) {
		cin >> query[q];
	}
}

void daminput() {
}

//TT(T,T):=モノイドの乗算
//require Monoid
template<class T>
class Segtree {
private:
	vector<T> seg;
	LL RN;
	typedef function<T(T, T)> TT;
	TT f;
	T te;
public:
	Segtree(LL N, TT _f, T e) :te(e) {
		RN = 1;
		while (RN < N)RN *= 2;
		seg.resize(2 * RN, te);
		f = _f;
	}
	Segtree(vector<T>& V, TT _f, T e) :te(e) {
		LL N = V.size();
		RN = 1;
		while (RN < N)RN *= 2;
		seg.resize(2 * RN, te);
		f = _f;
		for (LL n = 0; n < N; n++) seg[RN + n] = V[n];
		for (LL k = RN - 1; k >= 1; k--) {
			seg[k] = f(seg[2 * k], seg[2 * k + 1]);
		}
	}
	//set n-th as x(0 index!!!!!)
	void set(LL n, T x) {
		seg[RN + n] = x;
		n = (RN + n) / 2;
		while (n >= 1) {
			seg[n] = f(seg[2 * n], seg[2 * n + 1]);
			n /= 2;
		}
	}
	//change n-th number p to x*p(0 index!!!!!)
	void addl(LL n, T x) {
		seg[RN + n] = f(x, seg[RN + n]);
		n = (RN + n) / 2;
		while (n >= 1) {
			seg[n] = f(seg[2 * n], seg[2 * n + 1]);
			n /= 2;
		}
	}
	//change n-th number p to p*x(0 index!!!!!)
	void addr(LL n, T x) {
		seg[RN + n] = f(seg[RN + n], x);
		n = (RN + n) / 2;
		while (n >= 1) {
			seg[n] = f(seg[2 * n], seg[2 * n + 1]);
			n /= 2;
		}
	}
	//get [l,r] (0 index!!!!!)
	T get(LL l, LL r) {
		T ansl = te, ansr = te;
		r++;
		l += RN;
		r += RN;
		while (l < r) {
			if (l & 1) {
				ansl = f(ansl, seg[l]);
				l++;
			}
			if (r & 1) {
				r--;
				ansr = f(seg[r], ansr);
			}
			l >>= 1;
			r >>= 1;
		}
		return f(ansl, ansr);
	}
	//get n-th number(0 index!!!!!)
	T get(LL n) {
		return seg[RN + n];
	}
	T operator[](LL n) {
		return seg[RN + n];
	}
};

void solve() {
	Segtree<LL> seg(A, [](LL a, LL b) {
		return a + b;
	}, 0);
	for (int q = 0; q < Q; q++) {
		int t = query[3 * q];
		if (t == 0) {
			int p = query[3 * q + 1];
			int x = query[3 * q + 2];
			seg.addl(p, x);
		}
		else {
			int l = query[3 * q + 1];
			int r = query[3 * q + 2];
			cout << seg.get(l, r - 1) << "\n";
		}
	}
}

void naive() {
}

void outputinput() {
}