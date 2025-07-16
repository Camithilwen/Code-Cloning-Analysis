#include <iostream>
#include <string>

int main(){
	int n;
	std::string str;

	std::cin >> n;
	std::getline(std::cin, str);

	for (int i = 0; i < n; ++i){

		std::getline(std::cin, str);

		while(str.find("Hoshino") != std::string::npos){

			str.replace(str.find("Hoshino"), 7, "Hoshina");

		}

		std::cout << str << std::endl;
		
	}

	return 0;
}
