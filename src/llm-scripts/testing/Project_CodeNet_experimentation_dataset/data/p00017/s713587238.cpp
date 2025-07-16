#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#define pi 3.14159
using namespace std;

int main() {
	string str;
	int i;
	while(getline(cin, str)) {
		for(i = 0; i < 26; i++) {
			for(int j = 0; j < str.size(); j++) {
				if(str[j] != ' ' && str[j] != '.') {
					if(str[j] != 'a') {
						str[j] -= 1;
					} else str[j] = 'z';
				}
			}
			for(int j = 0; j < str.size() - 4; j++) {
				if(str[j] == 't' && str[j + 1] == 'h') {
					cout << str <<endl;
					i = 26;
					break;
					//if(str[j + 2] == 'e' ) {
						//cout << str <<endl;
						//i = 26;
						//break;
					//} else if(str[j + 2] == 'i' && str[j + 3] == 's'){
						//cout << str <<endl;
						//i = 26;
						//break;
					//} else if(str[j + 2] == 'a' && str[j + 3] == 't') {
						//cout << str <<endl;
						//i = 26;
						//break;
					//}
				}
			}
			
		}
	}

	return 0;
}