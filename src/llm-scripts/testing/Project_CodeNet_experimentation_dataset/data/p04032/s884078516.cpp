#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int n = int(s.size());
	if(n == 2 && s[0] == s[1]) return cout << 1 << ' ' << 2 << '\n', 0; 
	for(int i = 0; i < n - 2; ++i){
		string ac = s.substr(i, 3);
		if(ac[0] == ac[1] || ac[0] == ac[2] || ac[1] == ac[2]){
			return cout << i + 1 << ' ' << i + 3 << '\n', 0;
		}
	}
	cout << -1 << ' ' << -1 << '\n';
	return 0;
}