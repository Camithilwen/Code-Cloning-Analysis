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

LL calc(LL N, LL M, LL D) {
	VLL V(M,1);
	LL ans = 0;
	while (true) {
		for (LL m = 0; m < M - 1; m++) {
			if (abs(V[m] - V[m + 1]) == D)ans++;
		}
		LL m = M-1;
		for (; m >= 0; m--) {
			if (V[m] != N)break;
		}
		if (m == -1)return ans;
		V[m]++;
		for (LL mm = m + 1; mm < M; mm++)V[mm] = 1;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//for (LL n = 1; n <= 10; n++) {
	//	for (LL m = 2; m <= 6; m++) {
	//		for (LL d = 0; d < n; d++) {
	//			//cout << "n,m,d = " << n << "," << m << "," << d << ":";
	//			//cout << calc(n, m, d) << "/(n^m);\n";
	//			LL d0 = calc(n, m, d);
	//			LL d1 = 2*(m-1);
	//			for (LL p = 0; p < m - 2; p++)d1 *= n;
	//			d1 *= n - d;
	//			if (d0 != d1) {
	//				cout << "n,m,d = " << n << "," << m << "," << d << ":";
	//				cout << d0 << "vs" << d1 << "\n";
	//			}
	//		}
	//		cout << "\n";
	//	}
	//	cout << "####################\n";
	//}
	LL N, M, D;
	cin >> N >> M >> D;
	LD ans = (LD)2 * (M - 1) * (N - D) / N / N;
	if (D == 0)ans /= 2;
	cout << setprecision(12) << ans << "\n";
	return 0;
}
