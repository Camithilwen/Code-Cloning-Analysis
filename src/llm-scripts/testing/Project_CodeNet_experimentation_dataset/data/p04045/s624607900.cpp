#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	int N; cin >> N;
	int K; cin >> K;
	map<char, bool> mp;
	for (int i = 0; i < K; ++i) {
		char a; cin >> a;
		mp[a] = true;
	}

	for (int i = N; i < N * 100; ++i) {
		string s = to_string(i);
		bool flags = 0;
		for (int j = 0; j < s.length(); ++j) {
			if (mp[s[s.length() - j - 1]] == 1) {
				flags = 1;
				break;
			}
		}
		if (!flags) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}