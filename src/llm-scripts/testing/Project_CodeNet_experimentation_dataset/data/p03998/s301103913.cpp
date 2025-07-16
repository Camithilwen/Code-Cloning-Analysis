#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string a, b, c;
	int flag = 0;
	int sa = 0, sb = 0,sc = 0;

	cin >> a >> b >> c;
	
	while (1) {
	
		while (flag == 0) {
		
			if (a[sa] == 'a')flag = 0;
			else if (a[sa] == 'b')flag = 1;
			else if (a[sa] == 'c')flag = 2;
			 else if (a[sa] == '\0') {
				cout << 'A' << endl; return 0;
			}
			sa++;
		}
		while (flag == 1) {
			
			if (b[sb] == 'a')flag = 0;
			else if (b[sb] == 'b')flag = 1;
			else if (b[sb] == 'c')flag = 2;
			else if (b[sb] == '\0') {
				cout << 'B' << endl; return 0;
			}
			sb++;
		}
		while (flag == 2) {
			if (c[sc] == 'a')flag = 0;
			else if (c[sc] == 'b')flag = 1;
			else if (c[sc] == 'c')flag = 2;
			else if (c[sc] == '\0') {
				cout << 'C' << endl; return 0;
			}
			sc++;
		}
	}
}