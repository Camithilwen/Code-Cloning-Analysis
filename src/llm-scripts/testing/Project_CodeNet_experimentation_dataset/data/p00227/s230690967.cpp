#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int n, m;
	std::cin >> n >> m;
	while (n != 0 && m != 0) {
		int whole_price = 0;
		std::vector<int> vegi(n);
		for (auto &v : vegi) std::cin >> v;
		std::sort(vegi.begin(), vegi.end());
		for (auto i = 1; i <= n; ++i) {
			whole_price += (i % m == 0) ? 0 : vegi[n - i];
		}
		std::cout << whole_price << std::endl;
		std::cin >> n >> m;
	}
}
