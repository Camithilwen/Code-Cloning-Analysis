#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int b = 0;
	for(auto c : s) if(c == 'B') ++b;
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] != 'R') continue;
		for(int j = 0; j < n; ++j){
			if(s[j] != 'G') continue;
			ans += b;
			int x = i, y = j;
			if(x > y) swap(x, y);
			int d = y - x;
			if(d % 2 == 0 && s[x + d / 2] == 'B') --ans;
			if(x - d >= 0 && s[x - d] == 'B') --ans;
			if(y + d < n && s[y + d] == 'B') --ans;
		}
	}
	cout << ans << endl;
}