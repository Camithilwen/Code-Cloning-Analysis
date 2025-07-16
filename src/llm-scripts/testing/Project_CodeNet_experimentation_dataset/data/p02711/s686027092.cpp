#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	string n;
	cin >> n;
	string ans = "No";
	rep(i, 3) if (n[i] == '7') ans = "Yes";
	cout << ans << endl;
	return 0;
}
