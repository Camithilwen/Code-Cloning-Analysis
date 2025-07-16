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
	intt N; std::cin >> N;
	std::map<std::string, int> MAP;
	std::vector<std::string> s(N);
	for (auto& r : s) {
		std::cin >> r;
		++MAP[r];
	}
	intt M; std::cin >> M;
	std::vector<std::string> t(M);
	for (auto& r : t) {
		std::cin >> r;
		--MAP[r];
	}
	int max = -201;
	for (auto& r : MAP)
		max = std::max(max, r.second);

	std::cout << std::max(max, 0) << std::endl;
}
