#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
	const int INF = 10000000;
	int n, k, map[100][100], a, b, c;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

	while(true)
	{
		scanf("%d%d", &n, &k);
		if(n == 0 && k == 0)
			break;

		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
				map[i][j] = INF;
		}

		for(int g = 0; g < k; ++g)
		{
			scanf("%d", &a);
			if(a == 0)
			{
				//vZ
				int ans = -1;
				bool flag[100] = {};

				scanf("%d%d", &a, &b);
				q.push(pair<int, int>(0, a - 1));

				while(!q.empty())
				{
					pair<int, int> p = q.top();
					q.pop();
					int &cost = p.first, &num = p.second;
					if(flag[num])
						continue;
					flag[num] = true;

					if(num == b - 1)
					{
						ans = cost;
						for(int i = q.size(); i > 0; --i)
							q.pop();
						break;
					}

					for(int i = 0; i < n; ++i)
					{
						if(map[num][i] == INF || flag[i])
							continue;
						q.push(pair<int, int>(cost + map[num][i], i));
					}
				}

				printf("%d\n", ans);
			}
			else
			{
				//ÇÁ
				scanf("%d%d%d", &a, &b, &c);
				if(map[a - 1][b - 1] > c)
					map[a - 1][b - 1] = map[b - 1][a - 1] = c;
			}
		}
	}

	return 0;
}