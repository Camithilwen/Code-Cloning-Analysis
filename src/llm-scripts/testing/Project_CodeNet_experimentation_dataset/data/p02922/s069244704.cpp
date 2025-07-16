#include <iostream>

int main()
{
	int A, B;
	std::cin >> A >> B;
	if ((B-1)%(A-1)==0) std::cout << (B-1)/(A-1) << std::endl;
	else std::cout << (B-1)/(A-1) + 1 << std::endl;
	return 0;
}
