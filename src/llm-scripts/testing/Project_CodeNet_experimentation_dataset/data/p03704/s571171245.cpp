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

int D;
ll kotae = 0;
void keisan(ll A, int B, int C, vector<int> V) {
	if (B < C / 2) {
		ll k1 = 1, k2 = 1;
		rep(i, C - B - 1) k1 *= 10;
		rep(i, B) k2 *= 10;
		ll k = k1 - k2;
		if (A >= 0) {
			if (abs(A / k) < 10) {
				V.pb(A / k);
				keisan(A % k, B + 1, C, V);
				V.pop_back();
			}
			if (abs(A / k + 1) < 10) {
				V.pb(A / k + 1);
				keisan(A % k - k, B + 1, C, V);
			}
		}
		else {
			if (abs(A / k) < 10) {
				V.pb(A / k);
				keisan(A % k, B + 1, C, V);
				V.pop_back();
			}
			if (abs(A / k - 1) < 10) {
				V.pb(A / k - 1);
				keisan(A % k + k, B + 1, C, V);
			}
		}
	}
	else {
		if (A == 0) {
			ll kari = 1;
			rep(j, V.size()) {
				int kari2 = 0;
				if (j == 0) {
					rep1(k, 9) {
						if (k + V[j] < 10) kari2++;
					}
				}
				else {
					rep(k, 10) {
						if (k + V[j] >= 0 && k + V[j] < 10) kari2++;
					}
				}
				kari *= kari2;
			}
			if (C % 2) kari *= 10;
			kotae += kari;
		}
	}
}



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	cin >> D;

	for (int i = 19; i >= 2; i--) {
		vector<int> V;
		keisan(D, 0, i, V);
	}

	co(kotae);

	Would you please return 0;
}