#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

int main() {
	long long x;
	cin >> x;
	long long ans = 0;

	if (x % 11 == 0) {
		ans = x / 11 * 2;
	}
	else if(x % 11 <= 6) {
		ans = x / 11 * 2 + 1;
	}
	else {
		ans = x / 11 * 2 + 2;
	}

	cout << ans << endl;

	return 0;
}