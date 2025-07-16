#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> twin_primes(int upper) {
	std::vector<bool> suspects(upper + 1, true);
	suspects[0] = suspects[1] = false;
	std::vector<int> res;
	for (auto i = 2; i <= upper; ++i) {
		if (suspects[i]) {
			if (suspects[i - 2])
				res.push_back(i);
			for (auto j = 2 * i; j <= upper; j += i)
				suspects[j] = false;
		}
	}
	return res;
}
int main() {
	int n;
	std::cin >> n;
	auto primes = twin_primes(10000);
	while (n != 0) {
		auto prime = *(std::upper_bound(primes.begin(), primes.end(), n) - 1);
		std::cout << prime - 2 << ' ' << prime << std::endl;
		std::cin >> n;
	}
}
