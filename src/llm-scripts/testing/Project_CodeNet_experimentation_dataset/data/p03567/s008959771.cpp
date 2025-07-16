#include <iostream>
using namespace std;
int main(){
	string s;
	cin >> s;
	for(int i = 0; i < s.size()-1; i++){
		if(s[i]=='A'&&s[i+1]=='C'){
			cout << "Yes" << endl;
			exit(0);
		}
		if(s[i]=='a'&&s[i+1]=='c'){
			cout << "Yes" << endl;
			exit(0);
		}
	}
	cout << "No" << endl;
	return 0;
}
