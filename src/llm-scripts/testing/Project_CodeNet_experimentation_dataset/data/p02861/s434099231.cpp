#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>

int fact(int k) {
	int w = 1;
	for (int i = 2; i <= k; i++)
		w *= i;
	return w;
}

int main() {
	double sum = 0;
	std::vector<int> k;
	int n, x, y;
	std::cin >> n;
	std::vector<std::pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> x >> y;
		v[i].first = x, v[i].second = y;
		k.push_back(i);
	}
	for (int i = 0; i < n - 1; i++) {
		sum += std::sqrt((v[k[i]].first - v[k[i + 1]].first) * (v[k[i]].first - v[k[i + 1]].first) +
			(v[k[i]].second - v[k[i + 1]].second) * (v[k[i]].second - v[k[i + 1]].second));
	}
	while (std::next_permutation(k.begin(), k.end())) {
		for (int i = 0; i < n - 1; i++) {
			sum += std::sqrt((v[k[i]].first - v[k[i + 1]].first) * (v[k[i]].first - v[k[i + 1]].first) +
				(v[k[i]].second - v[k[i + 1]].second) * (v[k[i]].second - v[k[i + 1]].second));
		}
	}
	printf("%.10f", sum / fact(n));
	return 0;
}
