#include <iostream>
#include <algorithm>
#include <iomanip>

double avg(int n) {
	return (n+1)/2.0;
}

int main() {
	int n, k, p[2000010];
	std::cin >> n >> k;

	for (int i = 0; i < n; ++i)
		std::cin >> p[i];

	double sum = 0;
	for (int i = 0; i < k; ++i) {
		sum += avg(p[i]);
	}


	double ans = sum;
	for (int i = k; i < n; ++i) {
		sum -= avg(p[i-k]);
		sum += avg(p[i]);

		ans = std::max(ans, sum);
	}

	std::cout << std::setprecision(10) << std::fixed << ans;
}