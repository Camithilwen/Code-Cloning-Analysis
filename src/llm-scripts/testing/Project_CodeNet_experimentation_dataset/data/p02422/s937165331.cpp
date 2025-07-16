#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string s, t, u; int n, a, b;
int main() {
	cin >> s >> n;
	for(int i = 0; i < n; i++) {
		cin >> t;
		if(t == "print") cin >> a >> b, cout << s.substr(a, b - a + 1) << endl;
		if(t == "reverse") cin >> a >> b, reverse(s.begin() + a, s.begin() + b + 1);
		if(t == "replace") cin >> a >> b >> u, s.replace(a, b - a + 1, u);
	}
	return 0;
}