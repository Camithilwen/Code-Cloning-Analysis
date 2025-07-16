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

//世界の皆は頭ええな

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	ll N, D;
	cin >> N >> D;
	ll kotae = (N - 1) * D;
	ll A[200001], C[200001];
	C[0] = 1e18;
	rep1(i, N) {
		cin >> A[i];
		kotae += A[i];
		C[i] = min(C[i - 1] + D, A[i]);
	}
	ll mae = 1e18;
	for (int i = N - 1; i > 1; i--) {
		mae = min(mae + D, A[i + 1]);
		ll kari = min(mae, C[i - 1]) + D;
		kotae += min(A[i], kari);
	}
	co(kotae);

	Would you please return 0;
}