#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

int main()
{
	int N;
	string S;
	cin >> N >> S;

	vector<vector<int>> su(2, vector<int>((unsigned int)(N + 100), 0));

	su.at(0).at(0) = 0;
	su.at(1).at(0) = 0;
	for (int i = 0; i < N; ++i)
	{
		if (S.at(i) == 'W')
		{
			su.at(0).at(i + 1) = su.at(0).at(i) + 1;
			su.at(1).at(i + 1) = su.at(1).at(i);
		}
		else
		{
			su.at(0).at(i + 1) = su.at(0).at(i);
			su.at(1).at(i + 1) = su.at(1).at(i) + 1;
		}
	}

	int ret = (int)(3 * 1e5);
	int l_min;
	rep(i, N)
	{
		l_min = (su.at(0).at(i)) + (su.at(1).at(N) - su.at(1).at(i+1));
		ret = min(l_min, ret);
	}

	cout << ret << endl;

	return 0;
}