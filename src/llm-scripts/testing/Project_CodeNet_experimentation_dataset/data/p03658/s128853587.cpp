#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> Li(N, 0);
	rep(i, N) cin >> Li.at(i);
	
	sort(Li.begin(), Li.end());
	reverse(Li.begin(), Li.end());

	int ans = 0;
	rep(i, K)
	{
		ans += Li.at(i);
	}

	cout << ans << endl;

	return 0;
}