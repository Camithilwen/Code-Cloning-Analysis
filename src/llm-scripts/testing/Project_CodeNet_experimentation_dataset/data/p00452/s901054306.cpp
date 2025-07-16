#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>

int main() {
	std::int64_t n, m;
	std::vector<std::int64_t> in, pairSum;
	in.reserve(1000);
	pairSum.reserve(1000 * 1000);

	while (std::cin >> n >> m, n + m != 0) {
		in.push_back(0);
		for (int i = 0; i < n; ++i) {
			int p;
			std::cin >> p;
			in.push_back(p);
		}

		for (auto x : in)
			for (auto y : in)
				pairSum.push_back(x + y);

		std::sort(pairSum.begin(), pairSum.end());

		std::int64_t ans = 0;
		for (auto e : pairSum) {
			if (e > m)
				continue;

			auto it = std::upper_bound(pairSum.begin(), pairSum.end(), m - e);
			--it;
			ans = std::max(ans, e + *it);
		}

		std::cout << ans << std::endl;

		in.clear();
		pairSum.clear();
	}
}