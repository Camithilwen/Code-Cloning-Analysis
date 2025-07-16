#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(){
	map<char, int> m;
	m['I'] = 1;m['V'] = 5;m['X'] = 10;m['L'] = 50;
	m['C'] = 100;m['D'] = 500;m['M'] = 1000;
	string s;
	while(cin >> s){
		int i = 0, ans = 0;
		while(i < s.size()){
			char c = s[i];
			int t = 0;
			for(i;c == s[i] && i < s.size()-1;i++)t += m[c];
			if(m[c] < m[s[i]])ans -= t;
			else ans += t;
			if(i == s.size()-1)ans += m[s[i++]];
		}
		cout << ans << endl;
	}
	return 0;
}