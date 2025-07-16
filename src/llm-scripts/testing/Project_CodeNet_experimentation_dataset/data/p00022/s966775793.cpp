#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n, n)
	{
		long int ary[5001] = {};

		for (int i = 1; i <= n; i++)
		{
			cin >> ary[i];
		}
		for (int i = 1; i <= n; i++)
		{
			ary[i] += ary[i - 1];
		}

		long int ans = -9999999999;
		for (int i = 0; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				ans = max(ans, ary[j] - ary[i]);
			}
		}
		cout << ans << endl;
	}

	return 0;
}