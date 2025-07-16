#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, M, Q;
	cin >> N >> M >> Q;
	string S[2000];
	rep(i, N) cin >> S[i];
	int B[2001][2001] = {};
	int C[2001][2001] = {};
	int D[2001][2001] = {};
	rep(i, N) {
		rep(j, M) {
			B[i + 1][j + 1] = B[i + 1][j] + S[i][j] - '0';
			if (i != 0) C[i + 1][j + 1] = C[i + 1][j] + ((S[i - 1][j] - '0') & (S[i][j] - '0'));
			if (j != 0) D[i + 1][j + 1] = D[i + 1][j] + ((S[i][j - 1] - '0') & (S[i][j] - '0'));
		}
	}
	rep(j, M) rep(i, N) {
		B[i + 1][j + 1] += B[i][j + 1];
		C[i + 1][j + 1] += C[i][j + 1];
		D[i + 1][j + 1] += D[i][j + 1];
	}
	
	rep(q, Q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int kotae;
		kotae = B[c][d] - B[c][b - 1] - B[a - 1][d] + B[a - 1][b - 1];
		kotae -= C[c][d] - C[c][b - 1] - C[a][d] + C[a][b - 1];
		kotae -= D[c][d] - D[c][b] - D[a - 1][d] + D[a - 1][b];
		co(kotae);
	}

	Would you please return 0;
}