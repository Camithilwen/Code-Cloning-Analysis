#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	UL S[2001][2001] = {};
	UL J1[2001][2001] = {};
	UL J2[2001][2001] = {};

	void Query() {
		UL y1, y2, x1, x2; cin >> y1 >> x1 >> y2>> x2;
		y1--; x1--;
		UL mass = S[x2][y2] + S[x1][y1] - S[x1][y2] - S[x2][y1];
		UL J1s = J1[x2][y2] + J1[x1 + 1][y1] - J1[x1 + 1][y2] - J1[x2][y1];
		UL J2s = J2[x2][y2] + J2[x1][y1 + 1] - J2[x1][y2] - J2[x2][y1 + 1];
		cout << (mass - J1s - J2s) << endl;
	}

	void Solve() {
		UL H, W; cin >> H >> W;
		UL Q; cin >> Q;
		rep(y, H) rep(x, W) {
			char c; cin >> c;
			S[x + 1][y + 1] = (c - '0');
		}
		rep(y, H) rep(x, W) if (S[x][y + 1] && S[x + 1][y + 1]) J1[x + 1][y + 1] = 1;
		rep(y, H) rep(x, W) if (S[x + 1][y] && S[x + 1][y + 1]) J2[x + 1][y + 1] = 1;
		rep(y, H) rep(x, W) S[x + 1][y + 1] += S[x][y + 1];
		rep(y, H) rep(x, W) S[x + 1][y + 1] += S[x + 1][y];
		rep(y, H) rep(x, W) J1[x + 1][y + 1] += J1[x][y + 1];
		rep(y, H) rep(x, W) J1[x + 1][y + 1] += J1[x + 1][y];
		rep(y, H) rep(x, W) J2[x + 1][y + 1] += J2[x][y + 1];
		rep(y, H) rep(x, W) J2[x + 1][y + 1] += J2[x + 1][y];
		rep(i, Q) Query();
	}


	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}