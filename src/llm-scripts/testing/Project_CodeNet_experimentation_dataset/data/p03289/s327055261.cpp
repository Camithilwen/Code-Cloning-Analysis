#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_accepted(void) {
	string s;
	cin >> s;
	bool judge_a = false, judge_b = false, judge_c = false;

	int cnt_c = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i == 0) {
			if (s[i] == 'A') judge_a = true;
			else             break;
		}
		else if (s[i] == 'C'){
			if (i >= 2 && i < s.size() - 1) {
				cnt_c++;
			}
		}
		else {
			if (s[i] < 'a') {
				judge_c = false;
				break;
			}
			else judge_c = true;
		}
	}

	if (cnt_c == 1) judge_b = true;

	if (judge_a & judge_b & judge_c) {
		cout << "AC" << endl;
	}
	else {
		cout << "WA" << endl;
	}
}

int main()
{
	b_accepted();
    return 0;
}