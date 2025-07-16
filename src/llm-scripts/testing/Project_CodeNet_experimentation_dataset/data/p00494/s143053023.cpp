#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<set>
#include<map>

using namespace std;


int main() {
	string s;
	cin >> s;

	vector<pair<char, int>> v;

	char last = s[0];
	int cnt = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == last) {
			cnt++;
		}
		else {
			v.push_back(make_pair(last, cnt));
			last = s[i];
			cnt = 1;
		}
	}
	v.push_back(make_pair(last, cnt));

	int ans = 0;
	for (int i = 1; i < v.size() - 1; i++) {
		if (v[i - 1].first == 'J' && v[i].first == 'O' && v[i + 1].first == 'I') {
			if (v[i - 1].second >= v[i].second && v[i].second <= v[i + 1].second) {
				ans = max(ans, v[i].second);
			}
		}
	}

	cout << ans << endl;

	return 0;
}

