#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) *b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};


///////////////////////////


int main() {

	ll N;
	cin >> N;

	vector<ll> A(N + 1,0);
	repn(i, N) cin >> A[i];

	sort(++A.begin(), A.end());

	vector<ll> B(1);
	vector<ll> C(1);
	ll M = 0;

	repn(i, N) {
		if (A[i] != A[i - 1]) {
			M++;
			C.push_back(A[i]);
			B.push_back(1);
		}

		else { B[M]++; }
	}

	ll ans = 0;

	for (ll i = M; i > 0; i--) {
		ll p = 1;

		while (p <= C[i]) {
			p *= 2;
		}

		ll X = p - C[i];
		auto itr = lower_bound(++C.begin(), C.end(), X);
		ll j = distance(C.begin(), itr);

		if (C[j] != X) { continue; }

		if (i == j) { ans += B[i] / 2; }
		if (j < i) { ans += min(B[i], B[j]); B[j] -= min(B[i], B[j]); }
		
	}

	cout << ans;

	system("PAUSE");

}



