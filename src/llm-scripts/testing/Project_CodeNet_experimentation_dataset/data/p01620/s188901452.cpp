#ifndef _WIN32
#include<iostream>
#endif 

#include<cmath>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

#define FOR(i,bg,ed) for(int i = (bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
struct cww {
	cww() {
		ios::sync_with_stdio(false);
		cin.tie(0);
	}
}star;
template<typename T>
istream & operator>> (istream &is, vector<T>&v) {
	for (auto &it : v)is>> it;
	return is;
}
char f(char c) {
	if (c == 'a')return 'Z';
	if (c == 'A')return 'z';
	return c - 1;
}
int main() {
	int n;
	while (cin >> n, n) {
		vector<int> k(n);
		cin >> k;
		string s;
		cin >> s;
		int id = 0;
		for (auto &c : s) {
			REP(i,k[id]) {
				c = f(c);
			}
			id++;
			id %= n;

		}
		cout << s << endl;
	}

	return 0;
}