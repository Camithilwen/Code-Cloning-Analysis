#include <iostream>
#include <string>

//Hoshino search and replace Hoshina
void replace_word(std::string s){
	const std::string find_word("Hoshino");
	//Hoshino search
	std::string::size_type pos = s.find(find_word);
	while(pos != std::string::npos){
		//Hoshino replace Hoshina
		s.replace(pos, find_word.length(), "Hoshina");
		pos = s.find(find_word, pos + find_word.length());
	}
	//output
	std::cout << s << std::endl;
	return;
}

int main(){
	std::string s;
	int num;
	std::cin >> num; //data set
	std::getline(std::cin, s); //read a new line
	for(int i=0; i<num; ++i){
		//read text
		std::getline(std::cin, s);
		//replace
		replace_word(s);
	}
}