#include <iostream>
#include <algorithm>
#include<string>
#include<vector>
int main() {
	int ining;
	std::cin >> ining;
	std::string s;
	for (int i = 0; i < ining; ++i) {
		int co = 0;
		int ch = 0;
		int c = 0;
		while (std::cin >> s) {
			if (s == "OUT") {
				++co;
			}
			if (co == 3) {
				break;
			}
			if (s == "HIT") {
				++ch;
			}
			if (ch == 4) {
				--ch;
				++c;
			}
			if (s == "HOMERUN") {
				c += ch + 1;
				ch = 0;
			}
		}
		std::cout << c << std::endl;
	}
	}