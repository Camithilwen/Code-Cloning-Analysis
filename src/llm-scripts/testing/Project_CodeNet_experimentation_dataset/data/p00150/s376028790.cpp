#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int maxsize(0);
	vector<int> input;

	while (1)
	{
		int tmp;

		cin >> tmp;

		if (!tmp)
		{
			break;
		}

		input.push_back(tmp);

		(maxsize < tmp) ? (maxsize = tmp) : (0);
	}

	vector<int> prime, ans;

	for (int i(2); i <= maxsize; ++i)
	{
		for (vector<int>::iterator i2(prime.begin()), n2(prime.end()); i2 != n2; ++i2)
		{
			if ((i % *i2) == 0)
			{
				goto nx;
			}
		}

		prime.push_back(i);
		
		if (i != *prime.begin() && binary_search(prime.begin(), prime.end(), i - 2))
		{
			ans.push_back(i);
		}
		nx:;
	}

	for (vector<int>::iterator i(input.begin()), n(input.end()); i != n; ++i)
	{
		int out(*(--upper_bound(ans.begin(), ans.end(), *i)));

		cout << out - 2 << ' ' << out << endl;
	}	

	return 0;
}