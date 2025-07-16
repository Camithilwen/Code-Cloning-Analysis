#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N;
	cin >> N;
	string a, b, c;
	cin >> a >> b >> c;

	int ans = 0;
	for (int ii = 0; ii < N; ++ii){
		map<char, int> m;
		m[a[ii]]++;
		m[b[ii]]++;
		m[c[ii]]++;

		int maxVal = max(m[a[ii]], max(m[b[ii]], m[c[ii]]));
		ans += 3 - maxVal;
	}


		cout << ans << "\n";

	return 0;
}
