#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, k, m;
set<int> t;

void ck(int* b) {
		int s = 0;

		for (int i = 0; i < k; i++) {
			if (b[i] > 9)
				s = s * 100 + b[i];
			else
				s = s * 10 + b[i];
		}

		if (t.find(s) == t.end()) {
			t.insert(s);
			m++;
		}
}

int main()
{
	cin >> n >> k;

	while (n > 0 || k > 0) {
		vector<int> a(n);

		for (int i = 0; i < n; i++)
			cin >> a[i];

		m = 0;
		int i = (1 << k) - 1;
		t.clear();

		while (i < (1 << n)) {
			vector<int> b;
			for (int j = 0; j < n; j++) {
				if((1 << j) & i)
					b.push_back(j);
			}

			do {
				vector<int> c;
				for (int i = 0; i < k; i++)
					c.push_back(a[b[i]]);

				ck(&c[0]);
			} while (next_permutation(b.begin(), b.end()));

			int x = i & -i, y = i + x;
			i = ((i & ~y) / x >> 1) | y;
		}

		cout << m << endl;
		
		cin >> n >> k;
	}

	return 0;
}

