#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
#include <queue>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int a, b;
    string s;
    cin >> a >> b >> s;
    for (int i = 0 ; i < a ; i++) {
    	if (s[i] < '0' || s[i] > '9') {
    		cout << "No";
    		return 0;
		}
	}
	if (s[a] != '-') {
		cout << "No";
		return 0;
	}
	for (int i = a + 1 ; i < s.length() ; i++) {
		if (s[i] < '0' || s[i] > '9') {
    		cout << "No";
    		return 0;
		}
	}
	cout << "Yes";
}