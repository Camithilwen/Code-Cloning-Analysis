//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const long long M=1000000007;
//typedef long T;
//#include "math/mod.h"

//#include "math/modulo.h"

template<class T, long long M>
struct modulo {
	T n;
	T gcd_ext(T a, T b, T *x, T *y) {
		if (a == 0) {
			*x = 0;
			*y = 1;
			return b;
		}
		T x1, y1;
		T gcd = gcd_ext(b%a, a, &x1, &y1);
		*x = y1 - (b/a) * x1;
		*y = x1;
		return gcd;
	}
	modulo(T n): n(n<0? n%M+M: n%M) {}
	operator T() const { return n; }
	modulo operator-() {
		return modulo(-n);
	}
	modulo operator+(const modulo &o) {
		return modulo(n+o.n);
	}
	modulo operator-(const modulo &o) {
		return modulo(n-o.n);
	}
	modulo operator*(const modulo &o) {
		return modulo(n*o.n);
	}
	modulo operator/(const modulo &o) {
		T x, y;
		T g = gcd_ext(o.n, M, &x, &y);
		if (g != 1) return 0;
		else return modulo(n * (x % M));
	}
	bool operator<(const modulo &o) const {
		return n<o.n;
	}
	bool operator<=(const modulo &o) const {
		return n<=o.n;
	}
	bool operator>(const modulo &o) const {
		return n>o.n;
	}
	bool operator>=(const modulo &o) const {
		return n>=o.n;
	}
	bool operator==(const modulo &o) const {
		return n==o.n;
	}
	bool operator!=(const modulo &o) const {
		return n!=o.n;
	}
};

typedef modulo<long long, M> T;
//#include "math/comb.h"

void comb_inc_k(T &r, int n, int &k) {
        //C(n,k+1) = C(n,k) * (n-k) / (k+1)
	r = r * T(n-k) / T(k+1);
	k++;
}

void comb_dec_k(T &r, int n, int &k) {
        //C(n,k-1) = C(n,k) * k / (n-k+1)
	r = r * T(k) / T(n-k+1);
	k--;
}

void comb_inc_n(T &r, int &n, int k) {
        //C(n+1,k) = C(n,k) * (n+1) / (n+1-k)
	r = r * T(n+1) / T(n+1-k);
	n++;
}

void comb_dec_n(T &r, int &n, int k) {
        //C(n-1,k) = C(n,k) * (n-k) / n
	r = r * T(n-k) / T(n);
	n--;
}

T comb(int n, int k) {
    if (k*2 > n) k = n-k;
    if (n==0) return 0;
    T r = 1; //C(n,0)
    for (int i=0; i<k; ) comb_inc_k(r, n, i);
    return r;
}


int h,w,a,b;

int input() {
	if (scanf("%d %d %d %d", &h, &w, &a, &b) < 0) return 0;
	return 1;
}

void init() {
}

int solve() {
	T r = comb(h+w-2, h-1);

	int xn = h-a+b-1, xk = b-1;
	T x = comb(xn, xk);

	int yn = a-1+w-b-1, yk = w-b-1;
	T y = comb(yn, yk);

	for (int i=0; i<a; i++) {
		//T x = mod_combinations(h-a+i+b-1, b-1, M);
		//T y = mod_combinations(a-1-i+w-b-1, w-b-1, M);
		if (i) {
			comb_inc_n(x, xn, xk);
			comb_dec_n(y, yn, yk);
		}
		r = r-x*y;
	}
	/*
	T r = mod_combinations(h+w-2, h-1, M);
	T x = mod_combinations(h-a+b-1, b-1, M);
	T y = mod_combinations(a-1+w-b-1, w-b-1, M);
	for (int i=0; i<a; i++) {
		//T x = mod_combinations(h-a+i+b-1, b-1, M);
		//T y = mod_combinations(a-1-i+w-b-1, w-b-1, M);
		if (i) {
			T n = h-a+i+b-1, m = b-1;
			x = mod_div(x*n, n-m, M);

			n = a-1-i+w-b-1, m = w-b-1;
			y = mod_div(y*(n+1-m), n+1, M);
		}
		T z = mod_mul(x, y, M);
		//printf("%d: r=%ld %ld %ld %ld\n", i, r, x, y, z);
		r = mod_sub(r, z, M);
		
	}
	*/
	return r;
}

void output(int ans) {
	printf("%d\n", ans);
}

void cleanup() {
}

int main() {
	//precalc();
	//int ca; scanf("%d", &ca);
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}


