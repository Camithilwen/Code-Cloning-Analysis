#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	int mx = 0, g = 0;
	while(n--) {
		int x;
		std::cin >> x;
		g = gcd(g, x);
		mx = std::max(mx, x);
	}
	std::cout << (k % g == 0 && k <= mx ? "POSSIBLE\n" : "IMPOSSIBLE\n");
}