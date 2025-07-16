#include<iostream>
using namespace std;
int n, a, b, c;
int main() {
	while (true) {
		cin >> n; if (n == 0) { break; }
		for (int i = 0; i < n; i++) {
			cin >> a >> b >> c;
			if (a + b + c >= 240) { goto A; }
			if (a + b >= 180) { goto A; }
			if (a == 100 || b == 100 || c == 100) { goto A; }
			if (a + b + c >= 210) { goto B; }
			if (a + b + c >= 150 && (a >= 80 || b >= 80)) { goto B; }
			goto C;
		A:; cout << 'A' << endl; goto D;
		B:; cout << 'B' << endl; goto D;
		C:; cout << 'C' << endl; goto D;
		D:;
		}
	}
}