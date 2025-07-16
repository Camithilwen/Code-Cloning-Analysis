#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;cin>>s;
	auto pos = s.find("AC");
	if(pos!=string::npos){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}