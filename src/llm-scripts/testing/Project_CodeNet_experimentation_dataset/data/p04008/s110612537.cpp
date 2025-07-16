//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
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

int N, K;
int kotae;
int ne[100001], H[100001], D;
int dfs(int A) {
	int d = 1;
	D++;
	for (int v = H[A]; v; v = ne[v]) {
		d = max(d, dfs(v) + 1);
	}
	D--;
	if (d >= K && D > 1) {
		kotae++;
		return 0;
	}
	else return d;
}

const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char getcha() {
	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }
	return *ci++;
}
inline int getint() {
	int A = 0;
	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	N = getint();
	K = getint();

	if (getint() != 1) kotae++;
	for (int i = 2; i <= N; i++) {
		int a = getint();
		ne[i] = H[a];
		H[a] = i;
	}

	dfs(1);
	printf("%d", kotae);

	Would you please return 0;
}