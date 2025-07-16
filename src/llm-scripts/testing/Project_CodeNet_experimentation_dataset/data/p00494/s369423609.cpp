#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <utility>
#include <functional>

using namespace std;

#define LEN 1000000

char str[LEN];
int cnt[LEN];

int main() {
	char ch;
	int s = -1, ans = 0;

	while (cin >> ch) {
		if (str[s] != ch) {
			s++;
		}
		str[s] = ch;
		cnt[s]++;
	}

	for (int i = 0; i + 2 <= s; ++i) {
		if (str[i] == 'J' && str[i + 1] == 'O' && str[i + 2] == 'I') {
			if (cnt[i + 1] <= cnt[i] && cnt[i + 1] <= cnt[i + 2]) {
				ans = max(ans, cnt[i + 1]);
			}
		}
	}

	cout << ans << endl;

	return 0;
}