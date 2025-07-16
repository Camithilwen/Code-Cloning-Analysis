#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<list>
#include<stack>
#include<queue>
#include<cctype>
#include<iomanip>
#include<functional>
#include<numeric>
#include<map>
#include<set>
#define EPS 1e-10
using namespace std;
typedef long long llong;
int rome(char g) {
	switch (g) {
	case 'I':return 1;
	case 'V':return 5;
	case 'X':return 10;
	case 'L':return 50;
	case 'C':return 100;
	case 'D':return 500;
	case 'M':return 1000;
	default:return -1;
	}
}
int main() {
	string s;
	while (cin >> s) {
		int sum = 0;
		int i;
		for (i = 0; i < s.length() -1; i++) {
			if (rome(s[i]) < rome(s[i + 1])) {
				sum += rome(s[i + 1]) - rome(s[i]);
				i++;
				//cout << "sum += " << rome(s[i + 1]) - rome(s[i]) << "  ";
			}
			else {
				sum += rome(s[i]);
				//cout << "sum += " << rome(s[i]) << "  ";
			}
			//cout << "sum is " << sum << endl;
		}
		if (i == s.length() - 1)sum += rome(s[i]);
		cout << sum << endl;
	}
	return 0;
}