#include <bits/stdc++.h>

const int MAXN = 1010;
typedef long long LL;
int pri[MAXN], bak, n;
int ispri(int x) {
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0) return false;
	return true;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return a / gcd(a, b) * b; }
LL get(int x, int y) {
	if (x < 1 || y < 1 || x > n || y > n) return 1;
	if ((x & 1) == (y & 1))
		return pri[x + y >> 1] * pri[x + n * 3 - y + 1 >> 1];
	return lcm(lcm(get(x - 1, y), get(x, y - 1)), lcm(get(x + 1, y), get(x, y + 1))) + 1;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n; n += 2;
	int now = 2;
	while (bak < n * 2) {
		if (ispri(now)) pri[++bak] = now;
		++now;
	}
	for (int i = 2; i < n; ++i, std::cout << '\n')
		for (int j = 2; j < n; ++j)
			std::cout << get(i, j) << ' ';
	return 0;
}
