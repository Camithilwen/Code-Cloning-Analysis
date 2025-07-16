#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846264338327950L

int main() {
	int N;
	cin >> N;
	long long sum = 0;
	for (int ii = 1; ii <= N; ii++) {
		if (ii % 3 == 0 && ii % 5 == 0) {
			continue;
		}
		if (ii % 3 == 0 || ii % 5 == 0) {
			continue;
		}
		sum += ii;
	}
	cout << sum << endl;
}