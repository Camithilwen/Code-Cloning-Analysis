#include <bits/stdc++.h>
using namespace std;

int main(){
#ifdef _DEBUG
	//freopen("_in" , "r", stdin );
	//freopen("_out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	string s[3]; cin >> s[0] >> s[1] >> s[2];
	int i = 0;
	for(;;) {
		if (!s[i].size()) break;
		int t;
		if (s[i][0] == 'a') t = 0;
		if (s[i][0] == 'b') t = 1;
		if (s[i][0] == 'c') t = 2;
		s[i].erase(0, 1);
		i = t;
	}
	if (i == 0) cout << 'A';
	if (i == 1) cout << 'B';
	if (i == 2) cout << 'C';
	cout << '\n';
}
