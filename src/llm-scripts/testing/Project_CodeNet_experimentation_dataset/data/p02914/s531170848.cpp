//#include "bits/stdc++.h"

#define _USE_MATH_DEFINES
#include<cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include<iomanip>
#include<unordered_set>
#include<bitset>

using namespace std;

#define rep(i,a,b) for(int i=(a), i##_len=(b);i<i##_len;i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)

#define int ll
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

//typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector< vector<int> > mat;

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

const int MAX_ROW = 100010; // to be set appropriately
const int MAX_COL = 70; // to be set appropriately

struct BitMatrix {
	int H, W;
	bitset<MAX_COL> val[MAX_ROW];
	BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
	inline bitset<MAX_COL>& operator [] (int i) { return val[i]; }
};

int GaussJordan(BitMatrix &A, bool is_extended = false) {
	int rank = 0;
	for (int col = 0; col < A.W; ++col) {
		if (is_extended && col == A.W - 1) break;
		int pivot = -1;
		for (int row = rank; row < A.H; ++row) {
			if (A[row][col]) {
				pivot = row;
				break;
			}
		}
		if (pivot == -1) continue;
		swap(A[pivot], A[rank]);
		for (int row = 0; row < A.H; ++row) {
			if (row != rank && A[row][col]) A[row] ^= A[rank];
		}
		++rank;
	}
	return rank;
}

int linear_equation(BitMatrix A, vector<int> b, vector<int> &res) {
	int m = A.H, n = A.W;
	BitMatrix M(m, n + 1);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) M[i][j] = A[i][j];
		M[i][n] = b[i];
	}
	int rank = GaussJordan(M, true);

	// check if it has no solution
	for (int row = rank; row < m; ++row) if (M[row][n]) return -1;

	// answer
	res.assign(n, 0);
	for (int i = 0; i < rank; ++i) res[i] = M[i][n];
	return rank;
}

BitMatrix encodeBM(vector<int> v, int col)
{
	BitMatrix M(v.size(), col);
	rep(i, 0, (int)v.size())
	{
		rep(j, 0, col)
		{
			M[i][col - (j + 1)] = (v[i] >> j) & 1;
		}
	}
	return M;
}

vector<int> decodeBM(BitMatrix M)
{
	vector<int> v(M.H);
	rep(i, 0, M.H)
	{
		int n = 0;
		rep(j, 0, M.W)
		{
			if (M[i][j])
			{
				n |= 1LL << (M.W - (j + 1));
			}
		}
		v[i] = n;
	}
	return v;
}

int N;
int A[100010];

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	int ans = 0;
	rep(i, 0, N)
	{
		cin >> A[i];
		ans ^= A[i];
	}

	vector<int> v;
	rep(i, 0, N)
	{
		v.push_back(A[i] & (~ans));
	}

	BitMatrix M = encodeBM(v, 60);
	GaussJordan(M, false);

	v = decodeBM(M);

	int res = 0;
	for (auto n : v)
	{
		res ^= n;
	}

	ans += res * 2;
	cout << ans << endl;

	return 0;
}