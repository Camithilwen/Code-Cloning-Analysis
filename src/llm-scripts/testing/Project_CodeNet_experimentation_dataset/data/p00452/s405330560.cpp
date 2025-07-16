#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, D;

	while (true)
	{
		scanf("%d", &N);
		scanf("%d", &M);

		if (N == 0 && M == 0) { break; }

		vector<int> C; C.push_back(0);

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &D);

			if (D <= M)
			{
				C.push_back(D);
			}
		}

		vector<int> r1, r;

		for (int i = 0; i < C.size(); i++)
		{
			for (int j = i; j < C.size(); j++)
			{
				if (C[i] + C[j] <= M)
				{
					r1.push_back(C[i] + C[j]);
				}
			}
		}

		sort(r1.begin(), r1.end());

		r.push_back(r1[0]);

		for (int i = 0; i < r1.size(); i++)
		{
			if (r1[i - 1] != r1[i])
			{
				r.push_back(r1[i]);
			}
		}

		int ret = 0;

		for (int i = 0; i < r.size(); i++)
		{
			int ptr = upper_bound(r.begin(), r.end(), M - r[i]) - r.begin() - 1;
			
			if (ptr >= 0)
			{
				ret = max(ret, r[i] + r[ptr]);
			}
		}

		printf("%d\n", ret);
	}

	return 0;
}