#include <iostream>
#include <vector>

using namespace std;

class BIT {
public:
	BIT(int n) : a(n) {}

	void add(int p, long long num)
	{
		while (p < a.size()) {
			a[p] += num;
			p |= p + 1;
		}
	}

	/* i から j までの和 */
	long long sum(int i, int j)
	{
		long long s = 0, t = 0;
		i--;
		while (i >= 0) {
			s += a[i];
			i = (i & (i + 1)) - 1;
		}
		while (j >= 0) {
			t += a[j];
			j = (j & (j + 1)) - 1;
		}
		return t - s;
	}

private:
	vector<long long> a;
};

int main()
{
	int n, q;
	cin >> n >> q;
	BIT b(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		b.add(i, a);
	}
	for (int i = 0; i < q; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		if (p == 1) {
			cout << b.sum(q, r - 1) << endl;
		} else {
			b.add(q, r);
		}
	}

	return 0;
}