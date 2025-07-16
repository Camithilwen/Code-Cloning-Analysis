#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const double PI = 3.1415926535897932;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<double> P(N);
	rep(i, N) {
		cin >> P[i];
		P[i] = (P[i] + 1) / 2.0;
	}
	vector<double> Sm(N, 0);

	for (int i = 0; i < K; ++i) {
		Sm[0] += P[i];
	}
	double max_sum = Sm[0];
	int idx = 0;

	for (int i = 1; i <= (N - K); ++i) {
		Sm[i] = Sm[i - 1] - P[i - 1] + P[i + K - 1];
		if (Sm[i] > max_sum) {
			idx = i;
			max_sum = Sm[i];
		}
	}
	cout << fixed << setprecision(10) << max_sum << endl;
	return 0;
} 