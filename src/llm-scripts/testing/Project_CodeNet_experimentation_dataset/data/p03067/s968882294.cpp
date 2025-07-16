#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;

	if ((a < c && b > c) || (a > c&& b < c)) puts("Yes");
	else puts("No");

	return 0;
}