#include<iostream>
#include<string>

int main() {
	int K;
	std::string S;
	std::cin >> K >> S;
	if (S.size() <= K) std::cout << S << std::endl;
	else {
		std::string answer = S.substr(0, K);
		answer += "...";
		std::cout << answer << std::endl;
	}
	return 0;
}