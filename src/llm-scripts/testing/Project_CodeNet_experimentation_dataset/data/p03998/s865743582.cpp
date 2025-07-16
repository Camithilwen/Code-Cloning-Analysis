#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	vector<string> s(3);
	for(int i = 0; i < 3; ++i) {
		cin >> s[i];
		reverse(s[i].begin(), s[i].end());
	}
	
	int now = 0;
	for(int i = 0; i < 300; ++i) {
		
		if( s[now].empty() ) {
			cout << (char)(now + 'A') << endl;
			return 0;
		}
		
		char c = s[now].back();
		s[now].pop_back();
		now = (int)(c - 'a');
	}
	
	return 0;
}
