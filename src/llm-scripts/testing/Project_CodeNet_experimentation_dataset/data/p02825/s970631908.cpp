#include <bits/stdc++.h>

using namespace std;

vector<string> p[8] = {
	{}, 

	{}, 

	{},
 
	{"aa.",
  	"..a",
  	"..a"},
 
 	{"aabc",
  	"ddbc",
  	"bcaa",
  	"bcdd"},
 
 	{"aabba",
  	"bcc.a",
  	"b..cb",
  	"a..cb",
  	"abbaa"},
 
 	{"aabc..",
  	"ddbc..",
  	"..aabc",
  	"..ddbc",
  	"bc..aa",
  	"bc..dd"},
 
 	{"aabbcc.",
  	"dd.dd.a",
  	"..d..da",
  	"..d..db",
  	"dd.dd.b",
  	"..d..dc",
  	"..d..dc"}
};

int main() {
	int n;
	cin >> n;

	if(n <= 2) {
		cout << -1 << '\n';
		return 0;
	}

	vector<string> s(n, string(n, '.'));

	function<void(int, int, int)> draw = [&] (int x, int y, int w) {
		for(int i = 0; i < w; ++i) {
			for(int j = 0; j < w; ++j) {
				s[i + x][j + y] = p[w][i][j];
			}
		}
	};

	while(n >= 8) {
		draw(n - 4, n - 4, 4);
		n -= 4;
	}

	draw(0, 0, n);

	for(int i = 0; i < s.size(); ++i) {
		cout << s[i] << '\n';
	}

	return 0;
}