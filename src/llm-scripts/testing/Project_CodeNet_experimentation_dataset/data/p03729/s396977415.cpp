#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	if (a.at(a.length() - 1) == b.at(0) && b.at(b.length() - 1) == c.at(0))cout << "YES" << endl;
	else cout << "NO" << endl;
}