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

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 998244353;
const long long INF = 1e18;
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> PLL;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef unsigned long long ULL;
//typedef boost::multiprecision::cpp_int bigint;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	LL N;
	cin >> N;
	string S;
	cin >> S;
	VLL M(2 * N + 1, 0), C(2 * N + 1,0);
	VLL Ds;
	for (LL n = 0; n < N; n++) {
		if (S[n] == 'D')Ds.push_back(n + 1);
		if (S[n] == 'M')M[n + 1]++;
		if (S[n] == 'C')C[n + 1]++;
		M[n + 1] += M[n];
		C[n + 1] += C[n];
	}
	for (LL n = N + 1; n <= 2 * N; n++) {
		M[n] = M[n - 1];
		C[n] = C[n - 1];
	}
	VLL DP(2 * N + 1, 0);
	for (LL n = N; n >= 1; n--) {
		DP[n] = DP[n + 1];
		if (S[n - 1] == 'M')DP[n] += C.back() - C[n];
	}
	LL Q;
	cin >> Q;
	for (LL q = 0; q < Q; q++) {
		LL K;
		cin >> K;
		LL ans = 0;
		for (LL d : Ds) {
			LL temp = DP[d + 1] - DP[d + K] - (M[d + K - 1] - M[d]) * (C.back() - C[d + K-1]);
			ans += temp;
		}
		cout << ans << "\n";
	}
	return 0;
}
