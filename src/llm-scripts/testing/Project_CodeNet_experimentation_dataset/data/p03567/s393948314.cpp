#include <iostream>
#include <regex>
using namespace std;

int main() {
	string S;
	cin >> S;
	cout << (regex_search(S.begin(), S.end(), regex("AC")) ? "Yes" : "No") << endl;
}