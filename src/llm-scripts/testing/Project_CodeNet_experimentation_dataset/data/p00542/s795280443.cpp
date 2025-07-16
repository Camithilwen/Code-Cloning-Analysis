#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	cout << a + b + c + d - min(min(min(a, b), c), d) + max(e, f) << endl;
	cin >> c;
}