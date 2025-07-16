#include<bits/stdc++.h>
using namespace std;
char getClass(int m, int e, int j) {
	if (m == 100 || e == 100 || j == 100 || (m + e) / 2 >= 90
			|| (m + e + j) / 3 >= 80)
		return 'A';
	if ((m + e + j) / 3 >= 70 || (m + e + j) / 3 >= 50 && m >= 80 || e >= 80)
		return 'B';
	return 'C';
}
int main() {
	int n, pm, pe, pj;
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) {
			cin >> pm >> pe >> pj;
			cout << getClass(pm, pe, pj) << endl;
		}
	}
	return 0;
}