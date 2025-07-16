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

pair<int, bool> P[100001];
bool dame[100001];

pair<int, bool> Find(int A) {
	if (P[A].first < 0) return mp(A, 0);
	auto p = Find(P[A].first);
	P[A].first = p.first;
	P[A].second ^= p.second;
	return P[A];
}

bool Unite(int A, int B) {
	auto a = Find(A);
	auto b = Find(B);
	if (a.first == b.first) {
		if(a.second == b.second) dame[a.first] = true;
		return false;
	}
	if (P[a.first].first > P[b.first].first) swap(a, b);
	P[a.first].first += P[b.first].first;
	dame[a.first] |= dame[b.first];
	P[b.first] = mp(a.first, !(a.second ^ b.second));
	return true;
}

int Size(int A) {
	return -P[Find(A).first].first;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N = getint(), M = getint();
	rep1(i, N) P[i] = mp(-1, 0);
	rep(i, M) {
		int a = getint(), b = getint();
		Unite(a, b);
	}

	ll x = 0, y = 0, z = 0;
	rep1(i, N) {
		if (Find(i).first == i) {
			if (Size(i) > 1) {
				if (dame[i]) y++;
				else x++;
			}
			else z++;
		}
	}
	co(x * x + (x + y) * (x + y) + 2 * N * z - z * z);

	Would you please return 0;
}