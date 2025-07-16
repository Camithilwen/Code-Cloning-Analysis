#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

int main() {
	long long N, M; std::cin >> N >> M;
	std::map<long long, long long> C;
	std::vector<long long> D(N + 1);
	long long wa = 0;
	long long ac = 0;
	for (int i = 0; i < M; ++i) {
		long long c; std::string s;
		std::cin >> c >> s;
		if (s == "WA" && D[c] != 1) {
			D[c] = 5;
			++C[c];
			++wa;
		}
		if (s == "AC" && D[c] != 1) {
			D[c] = 1;
			++ac;
		}
	}
	for (int i = 0; i < N + 1; ++i) {
		if (D[i] == 5)
			wa -= C[i];
	}
	std::cout << ac << " " << wa << std::endl;


	return 0;
}
