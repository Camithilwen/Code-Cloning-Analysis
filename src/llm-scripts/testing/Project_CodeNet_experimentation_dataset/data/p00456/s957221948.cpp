#include <iostream>
#include <algorithm>
using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0533

int main() {
	int a[10], b[10];
	for (int i = 0; i < 10; i++) cin >> a[i];
	for (int i = 0; i < 10; i++) cin >> b[i];
	sort(a, a + 10);
	sort(b, b + 10);
	cout << (a[7] + a[8] + a[9]);
	cout << " ";
	cout << (b[7] + b[8] + b[9]) << endl;
	return 0;
}