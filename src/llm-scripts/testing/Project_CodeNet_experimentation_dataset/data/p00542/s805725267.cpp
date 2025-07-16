#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxof(const int a[]) {
	int i;
	int max = a[0];

	for (i = 1; i < 8; i++) {
		if (a[i] > max) max = a[i];
	}
	return max;
}

int main() {
	int a, b, c, d, e, f;
	int r1, r2, r3,r4,r5, r6, r7, r8;
	cin >> a >> b >> c >> d >> e >> f;
	r1 = a + b + c + e;
	r2 = a + b + c + f;
	r3 = a + b + d + e;
	r4 = a + b + d + f;
	r5 = a + c + d + e;
	r6 = a + c + d + f;
	r7 = b + c + d + e;
	r8 = b + c + d + f;
	int ar[] = { r1, r2, r3,r4,r5, r6, r7, r8 };
	cout << maxof(ar) << endl;
}
