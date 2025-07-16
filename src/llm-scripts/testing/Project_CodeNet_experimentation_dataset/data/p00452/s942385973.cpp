#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int N, M;
	while (cin >> N >> M, N || M)
	{
		vector<int> point(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> point[i];
		}
		point.push_back(0);
		vector<int> sum;
		for (int i = 0; i <= N; ++i)
		{
			for (int j = 0; j <= N; ++j)
			{
				sum.push_back(point[i] + point[j]);
			}
		}
		int ans = 0;
		sort(sum.begin(), sum.end());
		for (int i = 0; i < sum.size(); ++i)
		{
			if (M - sum[i] < 0)
			{
				continue;
			}
			int left = 0;
			int right = sum.size();
			while (left < right)
			{
				int middle = (left + right) / 2;
				if (sum[i] + sum[middle] > M)
				{
					right = middle;
				}
				else if (sum[i] + sum[middle] < M)
				{
					left = middle + 1;
				}
				else
				{
					break;
				}
			}
			ans = max(ans, sum[i] + sum[right - 1]);
		}
		cout << ans << endl;
	}
}

int main()
{
	solve();
	return(0);
}