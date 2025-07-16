#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

int main() {
	intt N, M; std::cin >> N >> M;
	std::vector<intt> s(M);
	std::vector<intt> c(M);
	for (int i = 0; i < M; ++i) {
		std::cin >> s[i] >> c[i];
		if (s[i] == 1 && c[i] == 0 && N != 1) {
			std::cout << -1 << std::endl;
			return 0;
		}
	}
	for (int i = 0; i < M; ++i) {
		if (s[i] > N) {
			std::cout << -1 << std::endl;
			return 0;
		}
		for (int j = 0; j < M; ++j) {
			if (s[i] == s[j] && c[i] != c[j]) {
				std::cout << -1 << std::endl;
				return 0;
			}
		}
	}
	intt ans = 0;
	bool m1 = false;
	bool m2 = false;
	bool m3 = false;
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;

	for (int i = 0; i < M; ++i) {
		if (s[i] == 1) {
			m3 = true;
			p3 = i;
		}
		if (s[i] == 2) {
			m2 = true;
			p2 = i;
		}
		if (s[i] == 3){
			m1 = true;
			p1 = i;
		}
	}
	if (N == 3) {
		if (m3 == true)
			ans += c[p3] * 100;
		if (m2 == true)
			ans += c[p2] * 10;
		if (m1 == true)
			ans += c[p1];
	}
	else if (N == 2) {
		if (m3 == true)
			ans += c[p3] * 10;
		if (m2 == true)
			ans += c[p2];
	}
	else if (N == 1) {
		if (m3 == true)
			ans += c[p3];
	}

	if (N == 3 && ans < 100)
		ans += 100;
	if (N == 2 && ans < 10)
		ans += 10;

	std::cout << ans << std::endl;

	return 0;
}