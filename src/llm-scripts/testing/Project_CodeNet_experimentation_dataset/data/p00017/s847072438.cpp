#include<iostream>
#include<vector>
#include<string>
using namespace std;

string Caesar(string a) {
	for (int b = 0; b < a.length(); b++) {
		if (a[b] == 'z')a[b] = 'a';
		else if (a[b] >= 'a'&&a[b] < 'z')a[b] = a[b] + 1;
	}
	return a;
}
int main() 
{
	string a;
	while (getline(cin, a)) {
		for (int b = 0; b < 26; b++) {
		    a=Caesar(a);
			for (int c = 0; c < a.length() - 4; c++) {
				if (a[c] == 't'&&a[c + 1] == 'h') {
					if (a[c + 2] == 'e') { cout << a << endl; goto l; }
					else	if (a[c + 2] == 'a'&&a[c + 3] == 't') { cout << a << endl; goto l; }
					else	if (a[c + 2] == 'i'&&a[c + 3] == 's') { cout << a << endl; goto l; }
				}
			}
			if(a[a.length()-1]=='t'&&a[a.length() - 2] == 'h'&&a[a.length() - 3] == 'e') { cout << a << endl; break; }
		l:;
		}
	}
}