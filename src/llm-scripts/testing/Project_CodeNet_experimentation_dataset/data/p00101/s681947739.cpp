#include <iostream>

int main (){
    std::string rightName = "Hoshina";
    std::string wrongName = "Hoshino";

    //num of data n
    int n = 0;
    std::cin >> n;
    //skip "\n"
    std::cin.ignore();
    for(int i = 0; i < n; ++i){
        std::string line;
        //input string
        getline(std::cin, line);
        //find exist of wrongName 
        std::string::size_type pos = line.find(wrongName);
        while(pos != std::string::npos){
            //rename to rightName
            line.replace(pos, wrongName.size(), rightName);
            pos = line.find(wrongName, pos + rightName.size());
        }

        std::cout << line << std::endl;
    }
}