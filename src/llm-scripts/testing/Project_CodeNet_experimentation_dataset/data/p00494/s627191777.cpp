#include <bits/stdc++.h>

using namespace std;

int CountOfJOI[3];
const string target = "JOI";

int main() {
	int len, curPos, k;
	string input;

	k = 0;
	cin >> input;
	len = input.size();
	curPos = 0;
	while (curPos < len) {
		if (input[curPos] != 'J') {
			++curPos;
			continue;
		}
		memset(CountOfJOI, 0, sizeof(CountOfJOI));
		for (int i = 0; i < 3; ++i) {
			while (curPos < len && input[curPos] == target[i]) {
				++curPos;
				++CountOfJOI[i];
			}
		}
		if (CountOfJOI[1] <= CountOfJOI[0] && CountOfJOI[1] <= CountOfJOI[2]) {
			k = max(k, CountOfJOI[1]);
		}
	}
	cout << k << endl;

	return 0;
}
