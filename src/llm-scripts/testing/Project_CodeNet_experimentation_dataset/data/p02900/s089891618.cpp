#include <iostream>
#include <vector>

std::vector<long long> common_divisors(long long a, long long b) {
	if (a > b) std::swap(a, b);
	std::vector<long long> ret(0), st(0);
	for (int i = 1; i <= a / i; i++) {
		if (a % i == 0) {
			if (b % i == 0) ret.push_back(i);
			if (b % (a / i) == 0 && i < a / i) st.push_back(a / i);
		}
	}
	while (st.size()) {
		ret.push_back(st.back());
		st.pop_back();
	}
	return ret;
}

bool is_prime(long long n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= n / i; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	long long a, b;
	std::cin >> a >> b;
	std::vector<long long> v = common_divisors(a, b);
	long long ans = 1;
	for (auto i : v) {
		if (is_prime(i)) ans++;
	}
	std::cout << ans << '\n';
 
	return 0;
}