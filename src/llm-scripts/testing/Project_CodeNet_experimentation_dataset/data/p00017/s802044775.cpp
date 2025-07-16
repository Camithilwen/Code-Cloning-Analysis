#include <iostream>
#include <string>
using namespace std;

int main(){
	string s, strCopy;
	while (getline(cin, s)) {
		for(int j=0 ; j<26 ; j++){
			for(int i=0 ; i<s.size() ; i++){
				if(s[i]>='a' && s[i]<='z'){
					s[i] = (s[i]=='z')? 'a' : s[i] + 1;
				}
			}
			if( s.find( "the" ) != string::npos || s.find( "this" ) != string::npos || s.find( "that" ) != string::npos){
				cout << s << endl;
			}
		}
	}
	
	return 0;
}