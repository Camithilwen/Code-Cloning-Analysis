#ifdef __GNUC__
#pragma GCC target("avx2")
#pragma GCC optimize ("O30")
#pragma GCC optimize ("tree-vectorize")
#pragma GCC optimize("unroll-loops")
#define iss std::cin
#endif
#include "bits/stdc++.h"
#define rep(i, times) for(ll i = 0; i < (times); ++i)
#define p(x) (cout << (x) << "\n")
using ll = long long; using ld = long double; using namespace std;

ll N, cnt;
void all( ) {
	vector<vector<ll>> A;
	iss >> N; A.resize(3, vector<ll>(N));
	for (auto &abc : A) {
		for (auto &a : abc)  iss >> a;
	}		
	sort(begin(A[0]), end(A[0]));
	sort(begin(A[2]), end(A[2]));
	for (auto &b : A[1]) {
		cnt += (end(A[2]) - upper_bound(begin(A[2]), end(A[2]), b))
			* (lower_bound(begin(A[0]), end(A[0]), b) - begin(A[0]));
	}
	p(cnt);
}
int main( ) {
	cin.tie(0);	ios::sync_with_stdio(0);
	all( );
}