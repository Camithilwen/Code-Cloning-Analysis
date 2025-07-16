#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

#define INF 1e18
long long DP[5001][5001];

struct Constraint {
	long long H, P;

	Constraint(long long H = 0, long long P = 0):H(H), P(P){}

	bool operator<(const Constraint& r)const {
		return P+H < r.P+r.H;
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	vector<Constraint>C(N);
	for (int i = 0; i < N; i++) {
		int P, H; cin >> H >> P;
		C[i] = Constraint(H, P);
	}
	sort(C.begin(), C.end());

	for (int i = 0; i <= N; i++)for (int j = 0; j <= N; j++)DP[i][j] = INF;
	DP[0][0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (DP[i][j] == INF)continue;

			if (DP[i][j] <= C[i].H) {
				DP[i + 1][j + 1] = min(DP[i + 1][j + 1], DP[i][j] + C[i].P);
			}			
			DP[i + 1][j] = min(DP[i + 1][j], DP[i][j]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (DP[i][j]==0 || DP[i][j] == INF)continue;
			ans = max(ans, j);
		}
	}

	cout << ans << endl;

	return 0;
}
