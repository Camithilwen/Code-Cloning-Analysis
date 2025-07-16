#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	map <char, int> a;
	a.insert(map<char, int>::value_type('I', 1));
	a.insert(map<char, int>::value_type('V', 5));
	a.insert(map<char, int>::value_type('X', 10));
	a.insert(map<char, int>::value_type('L', 50));
	a.insert(map<char, int>::value_type('C', 100));
	a.insert(map<char, int>::value_type('D', 500));
	a.insert(map<char, int>::value_type('M', 1000));
	string c;
	while (cin >> c) {
		string d="";
		for (int i = c.length() - 1; i >= 0; i--)
			d += c[i];
		int sum = 0, e = 0;
		for (int i = 0; i < c.length(); i++) {
			if (a[d[i]] >= e) {
				sum += a[d[i]];
				e = a[d[i]];
			}
			else {
				sum -= a[d[i]];
			}
		}
		cout << sum << endl;
	}
}