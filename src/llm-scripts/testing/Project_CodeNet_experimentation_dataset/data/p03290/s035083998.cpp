#include<bits/stdc++.h>
using namespace std;


int main()
{
	int D, G, p[11], c[11];
	cin >> D >> G;
	for (int i = 0; i < D; ++i)
		cin >> p[i] >> c[i];
	int ans = 1e9;	
	for (int mask = 0; mask < 1 << D; ++mask)
	{
		int sum = 0, num = 0;
		for (int i = 0; i < D; ++i)
		{
			if (mask & 1 << i)
			{
				sum += (i + 1) * 100 * p[i] + c[i];
				num += p[i];
			}
		}
		if (sum >= G)
		{
			ans = min(ans, num);
		}
		else
		{
			for (int i = D - 1; i >= 0; --i)
			{
				if (mask & 1 << i)
				{
					continue;
				}
				for (int j = 0; j < p[i]; j++)
				{
					if (sum >= G)
					{
						break;
					}
					sum += 100 * (i + 1);
					num++;
				}
			}
			ans = min(ans, num);
		}
	}
	cout << ans << endl;
}
