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

inline int getint_mae() {
	char C = getchar_unlocked();
	int A = C - '0';
	while (isdigit(C = getchar())) A = A * 10 + C - '0';
	return A;
}

const int cm = 1 << 17;
char cn[cm], *ci = cn + cm, ct;
inline char getcha() {
	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }
	return *ci++;
}
inline int getint() {
	int A = 0;
	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}

const int dm = 1 << 21;
char dn[dm], *di = dn, dt;
inline void putint(int X) {
	if (X == 0) {
		*di++ = '0';
		*di++ = '\n';
		return;
	}
	int keta = 0;
	char C[10];
	while (X) {
		*(C + keta) = '0' + X % 10;
		X /= 10;
		keta++;
	}
	for (int i = keta - 1; i >= 0; i--) *di++ = (*(C + i));
	*di++ = '\n';
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N = getint_mae(), M = getint_mae(), Q = getint_mae();
	char S[2001][2002];
	rep(i, N + 1) S[i][0] = '0';
	rep(i, M + 1) S[0][i] = '0';
	rep1(i, N) fread_unlocked(S[i] + 1, 1, M + 1, stdin);
	int B[2001][2001], C[2001][2001], D[2001][2001];
	rep(i, N) {
		rep(j, M) {
			B[i + 1][j + 1] = B[i + 1][j] + B[i][j + 1] - B[i][j] + S[i + 1][j + 1] - '0';
			C[i + 1][j + 1] = C[i + 1][j] + C[i][j + 1] - C[i][j] + ((S[i][j + 1] - '0') & (S[i + 1][j + 1] - '0'));
			D[i + 1][j + 1] = D[i + 1][j] + D[i][j + 1] - D[i][j] + ((S[i + 1][j] - '0') & (S[i + 1][j + 1] - '0'));
		}
	}

	rep(q, Q) {
		int a = getint(), b = getint(), c = getint(), d = getint();

		int kotae = B[c][d] - B[c][b - 1] - B[a - 1][d] + B[a - 1][b - 1] - C[c][d] + C[c][b - 1] + C[a][d] - C[a][b - 1] - D[c][d] + D[c][b] + D[a - 1][d] - D[a - 1][b];
		putint(kotae);

	}

	fwrite_unlocked(dn, di - dn, 1, stdout);

	Would you please return 0;
}