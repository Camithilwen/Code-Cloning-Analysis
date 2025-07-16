#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	
	string s;
	cin >> s;
	if(s.length() == 2) {
		if(s[0] == s[1]) cout << "1 2" << endl;
		else cout << "-1 -1" << endl;
		return 0;
	} else {	
		for(int i = 0; i < s.length() - 2; i++) {
			if(s[i] == s[i + 1] || s[i] == s[i + 2] || s[i + 1] == s[i + 2]) {
				cout << i + 1 << " " << i + 3 << endl;
				return 0;
			}
		}
	}
	
	cout << "-1 -1" << endl;
	return 0;
}