#include <iostream>
#include <vector>
using namespace std;

vector<char>stack;
// stack.back() will bring you to the last index

void checkForT(string s , char character, int index){
	if(!stack.empty() && stack.back()!= 'S'){
		stack.push_back(character);
	}
	else if(!stack.empty()){
		stack.pop_back();
	}
	else if(stack.empty()){
		stack.push_back(character);
	}
}

void checkForS(string s , char character, int index){
	stack.push_back(character);
}

int main(){
	string s;
	cin >> s; 

	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'S'){
			checkForS(s , s[i] , i);
		}
		else{ // else if stack[i]=='T'
			checkForT(s, s[i] , i);
		}
	}
	cout << stack.size() << endl; // Amount of elements left in stack
}