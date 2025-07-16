#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)

int main() {
	string L = "";
	for_(i,0,26) L += char('a' + i);
	for_(i,0,26) L += char('A' + i);
	
	int n;
	while (cin >> n, n) {
		vector< int > k(n);
		for_(i,0,n) cin >> k[i];
		
		string s;
		cin >> s;
		
		int m = s.size();
		for_(i,0,m) {
			int pos = L.find(s[i]);
			s[i] = L[(pos - k[i%n] + 52) % 52];
		}
		cout << s << endl;
	}
}