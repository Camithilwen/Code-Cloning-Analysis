#include <iostream>
#include <algorithm>
using namespace std;

int main()
{		
	int n, m;
	int p[1000];

	cin >> n >> m;

	while (n != 0 || m != 0) {
		for (int i = 0; i < n; i++)
			cin >> p[i];

		sort(p, p + n, greater<int>());

		int s = 0;
		for (int i = 0; i < n; i++) {
			if (i % m != m - 1)
				s += p[i];
		}
		cout << s << endl;

		cin >> n >> m;
	}

	return 0;
}

