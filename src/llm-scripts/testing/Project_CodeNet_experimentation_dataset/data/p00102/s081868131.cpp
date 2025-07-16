#include <iostream>
#include <vector>
#include <iomanip>

int main(int argc, char const* argv[])
{
	int n{};
	std::cin >> n;
	while (n) {
		std::vector<int> table{};
		for (int i = 0; i < n * n; i++) {
			int d;
			std::cin >> d;
			table.push_back(d);
		}
		for (int i = 0; i < n; i++) {
			auto hsum = 0;
			for (int j = 0; j < n; j++) {
				auto current = table[i * n + j];
				hsum += current;
				std::cout << std::setw(5) << std::right << current ;
			}
			std::cout << std::setw(5) << std::right << hsum;
			std::cout << std::endl;
		}
		int sum{};
		for (int i = 0; i < n; i++) {
			auto vsum = 0;
			for (int j = 0; j < n; j++) {
				auto current = table[j * n + i];
				vsum += current;
			}
			std::cout << std::setw(5) << std::right << vsum;
			sum += vsum;
		}
		std::cout << std::setw(5) << std::right << sum;
		std::cout << std::endl;
		std::cin >> n;
	}

	return 0;
}