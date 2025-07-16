#include <iostream>
#include <cmath>

using namespace std;

void sort(int *val, int n) {
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (val[i] < val[j]) swap(val[i], val[j]);
		}
	}
}

bool judge(int *val, int n, int num) {
	for (int i = 0; i < n; i++) {
		if (val[i] % num != 0) return false;
	}
	return true;
}

int main() {
	int n, i, k, harf, count;
	int val[3], div[10000];

	cin >> n;

	for (i = 0; i < n; i++) cin >> val[i];
	sort(val, n);

	harf = (int)sqrt(val[0]);

	div[0] = count = 1;
	for (i = 2; i <= harf; i++) {
		if (val[0] % i == 0) div[count++] = i;
	}

	cout << 1 << endl;
	for (i = 1; i < count; i++) {
		if (judge(&val[1], n - 1, div[i])) cout << div[i] << endl;
	}
	if (div[count - 1] == harf) count--;
	for (i = count - 1; i >= 0; i--) {
		k = (int)(val[0] / div[i]);
		if (judge(&val[1], n - 1, k)) cout << k << endl;
	}
	
	return 0;
}
