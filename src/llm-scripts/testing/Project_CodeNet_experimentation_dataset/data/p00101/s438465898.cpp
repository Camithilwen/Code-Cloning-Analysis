#include <iostream>
#include <string>

int main(){

	const std::string correct_word = "Hoshina";
	const std::string find_word = "Hoshino";
	
	int N;

	std::cin >> N;
	std::cin.ignore();

	for(int i = 0; i < N; ++i){
	
		std::string str;
		std::getline(std::cin,str);

		std::string::size_type pos = str.find(find_word);
		
		while(pos != std::string::npos){

			 str.replace(pos, find_word.length(), correct_word);

			 pos = str.find(find_word, pos + find_word.length());
		}
	
		std::cout << str << std::endl;
	
	}
	return 0;
}