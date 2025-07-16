#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
	int n;
	string str;
	getline(cin, str);
	n = atoi(str.c_str());
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		while (1) {
			size_t pos = str.find("Hoshino");
			if (pos == string::npos)
				break;
			str.replace(pos, 7, "Hoshina");
		}
		cout << str << endl;
	}
	return 0;
}