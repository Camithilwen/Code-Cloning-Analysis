#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void c_write_and_erase(void) {
	int n;
	cin >> n;
	map<long long, int>a;
	long long ain;
	for (int i = 0; i < n; i++) {
		cin >> ain;
		if (a.count(ain)) {
			a[ain]++;
		}
		else {
			a.insert(make_pair(ain, 1));
		}
	}

	int cnt = 0;
	map<long long, int>::iterator aptr = a.begin();
	for (aptr; aptr!=a.end(); aptr++) {
		if ((aptr->second) % 2 == 1) cnt++;
	}

	cout << cnt << endl;
}

int main()
{
    c_write_and_erase();
    return 0;
}