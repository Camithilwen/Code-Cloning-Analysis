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
	int N, M;
	cin >> N >> M;
	vector<string> S(M);
	vector<int> P(M);
	rep(i, M) {
		cin >> P[i] >> S[i];
		P[i]--;
	}
	vector<int> Ans(N, 0);

	int penalty = 0;
	int ac = 0;
	for (int i = 0; i < M; ++i) {
		if (S[i] ==  "AC" && Ans[P[i]] <= 0) {
			penalty += Ans[P[i]] * -1;
			Ans[P[i]] = 1;
			ac++;
		}
		else {
			if (Ans[P[i]] <= 0) {
				Ans[P[i]]--;
			}
		}
	}
	
	cout << ac << " " << penalty << endl;
	return 0;
} 