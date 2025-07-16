#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N; cin >> N;

	int x, y;

	vector<int> y_x(8, -1);

	for (int i = 0; i < N; i++)
	{
		cin >> y >> x;

		y_x[y] = x;
	}

	vector<int> perm(8);

	for (int i = 0; i < 8; i++) { perm[i] = i; }

	bool ok = true;

	do
	{
		ok = true;

		for (int y = 0; y < 8; y++)
		{
			if (y_x[y] != -1 && perm[y] != y_x[y])
			{
				ok = false;
			}
		}

		if (ok == true)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (i != j)
					{
						if (i - perm[i] == j - perm[j] || i + perm[i] == j + perm[j])
						{
							ok = false;
						}
					}
				}
			}
		}

		if (ok == true)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (perm[i] == j)
					{
						cout << 'Q';
					}
					else
					{
						cout << '.';
					}
				}

				cout << endl;
			}
		}
	} while (next_permutation(perm.begin(), perm.end()));

	return 0;
}