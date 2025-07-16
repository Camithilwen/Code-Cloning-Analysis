#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
const int MAX = 55556;
vector<bool> ok(MAX, true);
signed main(void)
{
	int n;
	vector<int> vec;

	cin >> n;
	ok[0] = ok [1] = false;
	rep(i, sqrt(MAX))
	{
		if (ok[i])
		{
			for (int j = 0; i * (j + 2) < MAX; j++)
			{	
				ok[i * (j + 2)] = false;
			}
		}
	}
	for(int i = 6; i < MAX; i += 5)
	{
		if (ok[i])
			vec.push_back(i);
	}
	sort(vec.begin(), vec.end());
	rep(i, n)
	{
		printf("%d%c", vec[i], i == n - 1?'\n':' ');
	}
	return 0;
}
