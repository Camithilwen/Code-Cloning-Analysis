#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N;
	cin >> N;

	vector <ll> A(N);
	vector <ll> B(N);
	vector <ll> C(N);
	for (int ii = 0; ii < N; ++ii) cin >> A[ii];
	for (int ii = 0; ii < N; ++ii) cin >> B[ii];
	for (int ii = 0; ii < N; ++ii) cin >> C[ii];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());

	ll ans = 0;
	for (int ii = 0; ii < N; ++ii){
		ll sum = 0;
		auto aitr = lower_bound(A.begin(), A.end(), B[ii]);
		ll anum = (aitr!=A.begin()) ? aitr - A.begin() : 0;

		auto citr = upper_bound(C.begin(), C.end(), B[ii]);
		ll cnum = C.end() - citr;

		ans += anum * cnum;
	}

	cout << ans << "\n";

	return 0;
}
