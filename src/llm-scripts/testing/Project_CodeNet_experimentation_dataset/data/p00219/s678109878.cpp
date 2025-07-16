#include<iostream>
#include<cstring>
using namespace std;
int n, a[10], x;
int main() {
	while (true) {
		cin >> n;
		if (n == 0) { break; }
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++) {
			cin >> x;
			a[x]++;
		}
		for (int i = 0; i < 10; i++) {
			if (a[i] == 0) { cout << '-' << endl; }
			else {
				for (int j = 0; j < a[i]; j++) { cout << '*'; }
				cout << endl;
			}
		}
	}
}