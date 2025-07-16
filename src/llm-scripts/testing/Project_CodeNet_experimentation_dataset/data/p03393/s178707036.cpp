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

	string S;
	cin >> S;

	string alp = "abcdefghijklmnopqrstuvwxyz";

	if (S.length() < 26) {
		for (int i = 0; i < alp.length(); i++) {
			if (S.find(alp.substr(i, 1)) == string::npos) {
				S += alp.substr(i, 1);
				break;
			}
		}
		cout << S << endl;
	}
	else {
		reverse(S.begin(), S.end());

		if (S == alp) {
			cout << -1 << endl;
		}
		else {
			size_t ii = 0;
			size_t pos = alp.find(S.substr(ii, 1), 0);

			while (pos != string::npos) {
				ii += 1;
				pos = alp.find(S.substr(ii, 1), pos);
			}

			string str = S.substr(ii, 1);

			for (size_t i = 0; i < ii; i++) {
				if (S.substr(i, 1) > str) {
					str = S.substr(i, 1);
					break;
				}
			}

			string ans = str + S.substr(ii + 1);

			reverse(ans.begin(), ans.end());

			cout << ans << endl;
		}
	}

	return 0;
}