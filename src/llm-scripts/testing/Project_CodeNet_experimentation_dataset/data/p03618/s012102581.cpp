#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long co[26] = { 0 };
int main() {
	string s;
	cin >> s;
	long long n = s.size();
	for (int i = 0; i < n; i++) {
		co[int(s[i] - 'a')]++;
	}
	long long ans = n * (n - 1) / 2 + 1;
	for (int j = 0; j < 26; j++) {
		if (co[j] >= 2) {
			ans -= co[j] * (co[j] - 1) / 2;
		}
	}
	cout << ans << endl;
	return 0;
}