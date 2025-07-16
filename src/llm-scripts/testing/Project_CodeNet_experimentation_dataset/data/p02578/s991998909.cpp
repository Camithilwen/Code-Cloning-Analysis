#include<bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define FORR(i,a,b) for (int i = b - 1; i >= a; --i)
#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,0,n)

int main() {
	ll N;
	cin >> N;
	ll A, high = 0, ans = 0;

	REP (i, N) {
		cin >> A;
		high = max(A, high);
		ans += high - A;
	}

	cout << ans << endl;
	return 0;
}