#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	string name = "";
	while (1) {
		n--;
		name += (n % 26 + 'a');
		n /= 26;
		if (n == 0) break;
	}
	reverse(name.begin(), name.end());
	cout << name;
}
