#include <bits/stdc++.h>
using namespace std;

int main() {
	long long N;
	cin >> N;
	long long total = 0;
	for (long long i = 1; i * i <= N; i++) {
		if (N % i == 0) {
			total = i;
		}
	}
	long long result = N / total;
	long long count = 0;
	while (result != 0) {
		result = result / 10;
		count++;
	}
	cout << count << endl;
}