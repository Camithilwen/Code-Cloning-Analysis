#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int m, n;
	while (cin >> n >> m&&n != 0 && m != 0) {
		int a = n%m, b = (n - a) / m, d = 0, e[1000], sum = 0;
		string c, h = "";
		getline(cin, c);
		getline(cin, c);
		c += " ";
		for (int i = 0; i < c.length(); i++) {
			if (c[i] == ' ') {
				e[d] = atoi(h.c_str());
				h = "";
				d++;
			}
			else
				h += c[i];
		}
		sort(e, e + n);
		d = 0;
		for (int i = 0; i < a; i++) {
			sum += e[i];
			d++;
		}
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < m; j++) {
				if (j != 0) {
					sum += e[i*m + j+a];
				}
			}
		}
		cout << sum << endl;
	}
}