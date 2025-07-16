#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
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

//わけわかめ
int P[100001];
bool dame[100001];
int Find(int A) {
	if (P[A] < 0) return A << 1;
	return P[A] = Find(P[A] >> 1) ^ (P[A] & 1);
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint(), M = getint();
	rep1(i, N) P[i] = -1;
	rep(i, M) {
		int a = Find(getint());
		int b = Find(getint());

		//なんてセンスのない
		int a1 = a >> 1;
		int b1 = b >> 1;
		if (a1 == b1) {
			if (!((a ^ b) & 1)) dame[a1] = true;
			continue;
		}
		if (P[a1] > P[b1]) {
			P[b1] += P[a1];
			dame[b1] |= dame[a1];
			P[a1] = b ^ !(a & 1);
		}
		else {
			P[a1] += P[b1];
			dame[a1] |= dame[b1];
			P[b1] = a ^ !(b & 1);
		}
	}

	ll x = 0, y = 0, z = 0;
	rep1(i, N) {
		if (P[i] < 0) {
			if (P[i] == -1) z++;
			else if (dame[i]) y++;
			else x++;
		}
	}
	printf("%lld\n", x * x + (x + y) * (x + y) + 2 * N * z - z * z);

	Would you please return 0;
}