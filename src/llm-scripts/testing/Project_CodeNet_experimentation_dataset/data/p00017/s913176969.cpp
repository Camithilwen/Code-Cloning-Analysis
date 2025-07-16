#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	while(getline(cin, s)){
		for(int i = 0; i < 26; i++){
			for(int i = 0; s[i] != '\0'; i++){
				if(s[i] >= 97 && s[i] <= 122) s[i] = (s[i] - 97 + 1) % 26 + 97;
			}
			if(s.find("the", 0) != string::npos || s.find("this", 0) != string::npos || s.find("that", 0) != string::npos){
				cout << s << endl;
				break;
			}
		}
	}
	return 0;
}