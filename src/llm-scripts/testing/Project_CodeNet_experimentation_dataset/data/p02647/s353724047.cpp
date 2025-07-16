#pragma GCC optimize ("O2")
#pragma GCC target ("avx2")
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstring>
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
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
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
const int dm = 1400000;
char dn[dm], * di = dn;
const int MAX = 20000;
class unko {
public:
	char C[MAX * 7 + 10], *K[MAX + 10];
	constexpr unko() : C(), K() {
		auto di = C + 3;
		C[0] = '0';
		C[0] = ' ';
		C[0] = '\n';
		K[0] = C;
		K[1] = di;
		rep1(i, MAX) {
			int X = i;
			int keta = 0;
			char c[10] = {};
			while (X) {
				*(c + keta) = '0' + X % 10;
				X /= 10;
				keta++;
			}
			for (int j = keta - 1; j >= 0; j--)* di++ = (*(c + j));
			*di++ = ' ';
			*di++ = '\n';
			K[i + 1] = di;
		}
	}
};
constexpr unko f;
inline void putint(int X) {
	if (X > 20000) {
		int ue = X / 10;
		for (auto i = f.K[ue]; *i != ' '; i++) *di++ = *i;
		*di++ = '0' + X % 10;
		*di++ = ' ';
	}
	else for (auto i = f.K[X]; *i != '\n'; i++)* di++ = *i;
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint(), K = getint();

	int A[200001];
	rep(i, N) A[i] = getint();
	ll owa = ll(N) * N;

	rep(p, K) {
		int B[200001] = {};
		rep(i, N) {
			B[max(0, i - A[i])]++;
			B[min(N, i + A[i] + 1)]--;
		}
		ll kei = B[0];
		A[0] = B[0];
		rep1(i, N - 1) {
			kei += (A[i] = A[i - 1] + B[i]);
		}
		if (kei == owa) break;
	}

	rep(i, N) putint(A[i]);
	fwrite(dn, 1, di - dn, stdout);

	Would you please return 0;
}