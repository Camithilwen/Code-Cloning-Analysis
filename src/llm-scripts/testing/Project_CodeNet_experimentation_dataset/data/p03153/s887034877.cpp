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


	ll N, D;
	cin >> N >> D;
	int A[200001];
	ll C[200001];
	C[0] = 1e18;
	ll motomoto = (N - 1) * D;
	rep1(i, N) {
		cin >> A[i];
		motomoto += A[i];
		C[i] = min(C[i - 1], A[i] - i * D);
	}
	ll saishou = 1e18;
	ll setuyaku = 0;
	for (int i = N - 1; i > 1; i--) {
		saishou = min(saishou, A[i + 1] + (i + 1) * D);
		motomoto += A[i];
		ll kari = min(saishou - i * D, C[i - 1] + i * D);
		if (A[i] > kari) setuyaku += A[i] - kari;
	}
	co(motomoto - setuyaku);

	Would you please return 0;
}