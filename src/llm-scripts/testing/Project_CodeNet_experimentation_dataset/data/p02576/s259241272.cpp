#include<iostream>

int main() {
	int N,X,T;
	std::cin >> N >> X >> T;
	int tmp;
	tmp = N / X;
	if (N%X != 0) { tmp += 1; }
	std::cout << tmp * T << std::endl;
	return 0;

}