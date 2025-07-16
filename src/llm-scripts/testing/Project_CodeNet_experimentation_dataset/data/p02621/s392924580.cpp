#include<iostream>
#include<cmath>


int main() {
	int a = {};
	int a2 = {};
	int a3 = {};
	std::cin >> a;

	a2 =std::pow(a, 2);
	a3 = std::pow(a, 3);

	a = a + a2 + a3;
	std::cout << a << std::endl;
}