#include <iostream>
#include <string>
using namespace std;

int main() {
	int k;
	string s;
	cin >> k>>s;
	auto out = s;
	if(s.size()>k) out = s.substr(0,k) + "...";
	cout << out << endl;
	return 0;
}