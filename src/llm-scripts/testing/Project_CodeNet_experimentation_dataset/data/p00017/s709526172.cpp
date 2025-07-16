#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	while(1){
		getline( cin, str );
		if( str.length()==0 )	break;
		for( int i=0; i<=26; i++ ){
			for( int j=0; j<str.length(); j++ ){
				if( 'a'<=str[j] && str[j]<='z' ){
					str[j]++;
					if( str[j] == 'z'+1 )
						str[j] = 'a';
				}
			}
			if( str.find("the")+str.find("this")+str.find("that") != -3 ){
				cout << str << endl;
				break;
			}
		}
	}
	return 0;
}