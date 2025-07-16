#include<iostream>
#include<string>

int main() {
	std::string s;
	std::cin >> s;
	
	if (s == "RRR") std::cout << 3 << std::endl;
	if (s == "RRS") std::cout << 2 << std::endl;
	if (s == "RSR") std::cout << 1 << std::endl;
	if (s == "SRR") std::cout << 2 << std::endl;
	if (s == "RSS") std::cout << 1 << std::endl;
	if (s == "SRS") std::cout << 1 << std::endl;
	if (s == "SSR") std::cout << 1 << std::endl;
	if (s == "SSS") std::cout << 0 << std::endl;
	
	return 0;
}