#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	vector<string> S(3, "");

	for (long long i = 0; i < S.size(); i++) {
		cin >> S[i];
	}

	vector<list<long long>> v(3, list<long long>());

	for (long long i = 0; i < v.size(); i++) {
		for (long long j = 0; j < S[i].length(); j++) {
			if (S[i][j] == 'a') {
				v[i].push_back(0);
			}
			else if (S[i][j] == 'b') {
				v[i].push_back(1);
			}
			else {
				v[i].push_back(2);
			}
		}
		v[i].push_back(-1);
	}

	long long val = 0;
	long long dval = 0;
	while (v[0].size() * v[1].size() * v[2].size() != 0) {
		dval = v[val].front();
		v[val].pop_front();
		val = dval;
	}

	for (long long i = 0; i < v.size(); i++) {
		if (v[i].size() == 0) {
			if (i == 0) {
				cout << "A" << endl;
				break;
			}
			else if (i == 1) {
				cout << "B" << endl;
				break;
			}
			else {
				cout << "C" << endl;
				break;
			}
		}
	}

	return 0;
}