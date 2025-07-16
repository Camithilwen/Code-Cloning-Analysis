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
#define EPS 1e-10
using namespace std;
typedef long long llong;
void whatday(int m, int d) {
	int z;
	if (m == 1)z = d;
	else if (m == 2)z = 31 + d;
	else if (m == 3)z = 60 + d;
	else if (m == 4)z = 91 + d;
	else if (m == 5)z = 121 + d;
	else if (m == 6)z = 152 + d;
	else if (m == 7)z = 182 + d;
	else if (m == 8)z = 213 + d;
	else if (m == 9)z = 244 + d;
	else if (m == 10)z = 274 + d;
	else if (m == 11)z = 305 + d;
	else if (m == 12)z = 335 + d;
	if (z % 7 == 5)cout << "Monday" << endl;
	else if (z % 7 == 6 % 7)cout << "Tuesday" << endl;
	else if (z % 7 == 0 % 7)cout << "Wednesday" << endl;
	else if (z % 7 == 1 % 7)cout << "Thursday" << endl;
	else if (z % 7 == 2 % 7)cout << "Friday" << endl;
	else if (z % 7 == 3 % 7)cout << "Saturday" << endl;
	else if (z % 7 == 4 % 7)cout << "Sunday" << endl;
}
int main() {
	int m, d;
	while (cin >> m >> d&&m&&d) {
		whatday(m, d);
	}
	return 0;
}