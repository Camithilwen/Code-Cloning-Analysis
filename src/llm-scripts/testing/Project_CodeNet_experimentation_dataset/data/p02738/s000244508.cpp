#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <limits>
#include <numeric>
#include <valarray>
#include <fstream>
#include <array>
#include <random>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using uint = uint32_t;
using LL = int64_t;
using ULL = uint64_t;
using PP = pair<LL, LL>;
template <typename T> using PriorityQ = priority_queue<T, vector<T>, greater<T> >;
#define REP(i, a, n) for(LL i = (a), i##_max_ = (n); i < i##_max_; ++i)
#define REM(i, a, n) for(LL i = (LL)(n) - 1, i##_min_ = (a); i >= i##_min_; --i)
#define FLOAT fixed << setprecision(16)
#define SPEEDUP { cin.tie(NULL); ios::sync_with_stdio(false); }
const int INF = 0x3FFFFFFF;
const LL INFLL = 0x3FFFFFFF3FFFFFFF;
const double INFD = 1.0e+308;
const double EPS = 1.0e-9;

void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
template <class T, class U> istream& operator>>(istream& ist, pair<T, U>& right) { return ist >> right.first >> right.second; }
template <class T, class U> ostream& operator<<(ostream& ost, const pair<T, U>& right) { return ost << right.first << ' ' << right.second; }
template <class T, class TCompatible, size_t N> void Fill(T(&dest)[N], const TCompatible& val) { fill(dest, dest + N, val); }
template <class T, class TCompatible, size_t M, size_t N> void Fill(T(&dest)[M][N], const TCompatible& val) { for (int i = 0; i < M; ++i) Fill(dest[i], val); }
template <class T> T Next() { T buf; cin >> buf; return buf; }
istream& Ignore(istream& ist) { string s; ist >> s; return ist; }
bool Inside(int i, int j, int h, int w) { return i >= 0 && i < h && j >= 0 && j < w; }

#ifdef ONLY_MY_ENVIR
#include "Accumulator.h"
#include "Algebraic.h"
#include "BinaryMatrix.h"
#include "BinaryTree.h"
#include "Bipartite.h"
#include "BIT.h"
#include "Compressor.h"
#include "Decompositions.h"
#include "DynamicMod.h"
#include "Factorization.h"
#include "FFT.h"
#include "FlowSolver.h"
#include "Graph.h"
#include "GraphUtil.h"
#include "IntMod.h"
#include "LazySegmentTree.h"
#include "LIS.h"
#include "Math.h"
#include "MathUtil.h"
#include "Matrix.h"
#include "MinCostFlowSolver.h"
#include "MinMax.h"
#include "Numbers.h"
#include "Optimize.h"
#include "Permutation.h"
#include "Polynomial.h"
#include "Position.h"
#include "Range.h"
#include "Rational.h"
#include "SegmentTree.h"
#include "SegmentTree2D.h"
#include "Sets.h"
#include "Shortest.h"
#include "SlidingWindow.h"
#include "SpanningTree.h"
#include "StringSearching.h"
#include "SuffixArray.h"
#include "Tree.h"
#include "TreeUtil.h"
#include "UnionFind.h"
#include "Util.h"
#include "VectorUtil.h"
#endif

#ifdef __GNUC__
typedef __int128 LLL;
istream& operator>>(istream& ist, __int128& val) { LL tmp; ist >> tmp; val = tmp; return ist; }
ostream& operator<<(ostream& ost, __int128 val) { LL tmp = val; ost << tmp; return ost; }
#endif

int N, MOD;
LL DP[6001][9001];

void add(LL& a, LL b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int main() {
	cin >> N >> MOD;
	N *= 3;

	const int Q = N / 2;

	DP[0][Q] = 1;
	REP(i, 0, N) {
		REP(k, -(i / 2), i + 1) {
			if (i + 1 <= N) add(DP[i + 1][Q + k + 1], DP[i][Q + k]);
			if (i + 2 <= N) add(DP[i + 2][Q + k - 1], DP[i][Q + k] * (i + 1) % MOD);
			if (i + 3 <= N) add(DP[i + 3][Q + k + 0], DP[i][Q + k] * (i + 1) % MOD * (i + 2) % MOD);
		}
	}

	LL sum = 0;
	REP(k, 0, N + 1) {
		add(sum, DP[N][Q + k]);
	}
	cout << sum << endl;
	return 0;
}

