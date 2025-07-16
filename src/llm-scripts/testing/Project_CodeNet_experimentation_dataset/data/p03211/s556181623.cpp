#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
	string s;
	cin >> s;
	int n = s.size();
	int t = 753;
	int d = 1000;
	string res;
	for (int i = 0; i + 2 < n; i++) {
				string ss = string(1, s[i]) + string(1, s[i + 1]) + string(1, s[i + 2]);
				if (abs(stoi(ss) - t) < d) {
					res = ss;
					d = abs(stoi(ss) - t);
				}
		
	}
	cout << d << endl;
}
