#include <iostream>
#include <cstdlib>

int main()
{
	long long s;
	std::cin >> s;
	
	int min = 56562;
	int diff;
	int num;
	int k = 1;
	while (true) {
		num = s / k % 1000;
		if (num < 100) break;
		diff = std::abs(753 - num);
		if (min > diff) min = diff;
		k *= 10;
	}
	
	std::cout << min << std::endl;
	
	return 0;
}
