#include <iostream>

using namespace std;

int main()
{
	int a[55556];
	fill(a, a + 55556, 1);
	a[0] = a[1] = 0;
	for (int i = 4; i < 55556; i += 2) {
		a[i] = 0;
	}
	for (int i = 3; i * i < 55556; i += 2) {
		if (a[i] == 1) {
			for (int j = i + i; j < 55556; j += i) {
				a[j] = 0;
			}
		}
	}

	int n;
	cin >> n;
	for (int i = 11, j = 0; j < n; i += 5) {
		if (a[i] == 1) {
			cout << i << (j == n - 1 ? "\n" : " ");
			j++;
		}
	}

	return 0;
}