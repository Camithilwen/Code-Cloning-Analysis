#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

string a, b, c;
int n;

int main() {
	cin >> n;
	cin >> a >> b >> c;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		set<char> s;
		s.insert(a[i]);
		s.insert(b[i]);
		s.insert(c[i]);
		//cerr << s.size() << endl;
		ret += s.size() - 1;
	}
	cout << ret << endl;
	return 0;
}
