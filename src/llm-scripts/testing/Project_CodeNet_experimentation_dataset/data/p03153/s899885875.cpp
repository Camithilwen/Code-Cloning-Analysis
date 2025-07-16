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

ll BIT1[200010];
ll BIT2[200010];

void add1(int A, ll B) {
	while (A > 0) {
		BIT1[A] = min(BIT1[A], B);
		A -= A & -A;
	}
}
ll query1(int A) {
	ll kotae = 1e18;
	while (A <= 200000) {
		kotae = min(kotae, BIT1[A]);
		A += A & -A;
	}
	return kotae;
}
void add2(int A, ll B) {
	while (A <= 200000) {
		BIT2[A] = min(BIT2[A], B);
		A += A & -A;
	}
}
ll query2(int A) {
	ll kotae = 1e18;
	while (A > 0) {
		kotae = min(kotae, BIT2[A]);
		A -= A & -A;
	}
	return kotae;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	ll N, D;
	cin >> N >> D;
	int A[200001];
	rep1(i, N) cin >> A[i];

	rep1(i, 200000) BIT1[i] = 1e18;
	rep1(i, 200000) BIT2[i] = 1e18;

	rep1(i, N) {
		add1(i, A[i] + i * D);
	}
	rep1(i, N) {
		add2(i, A[i] - i * D);
	}

	ll setuyaku = 0;
	for (int i = 2; i < N; i++) {
		ll kari1 = query1(i + 1) - i * D;
		ll kari2 = query2(i - 1) + i * D;
		if (A[i] > min(kari1, kari2)) {
			setuyaku += A[i] - min(kari1, kari2);
		}
	}

	ll motomoto = 0;
	rep1(i, N - 1) motomoto += A[i];
	rep1(i, N - 1) motomoto += A[i + 1];
	motomoto += (N - 1) * D;

	co(motomoto - setuyaku);

	Would you please return 0;
}