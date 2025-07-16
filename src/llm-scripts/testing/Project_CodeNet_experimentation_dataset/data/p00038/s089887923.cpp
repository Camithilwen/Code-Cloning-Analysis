#include <bits/stdc++.h>  

using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define repr(i, j) for(int i = j; i >= 0; --i)
#define INF (1 << 30)
#define MOD 1e9 + 7

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

int main() {
	int a[5];
	while(scanf("%d,%d,%d,%d,%d", &a[0], &a[1], &a[2], &a[3], &a[4]) != EOF) {
		bool three = false, four = false, straight = false, full = false;
		int pair = 0, count = 1;
		sort(a, a + 5);
		rep(i, 4) {
			if(a[i] == a[i+1]) ++count;
			else count = 1;
			if(count == 4) four = true;
			if(count == 3) three = true;
			else if(count == 2) ++pair;
		}
		rep(i, 4) {
			if(a[0] == 1 && a[1] == 10 && a[2] == 11 && a[3] == 12 && a[4] == 13) {
				straight = true;
				break;
			}
			if(a[i] != a[i + 1] - 1) {
				straight = false;
				break;
			}
			else straight = true;
		}
		if(three && pair == 2) full = true;
		if(four) cout << "four card" << endl;
		else if(full) cout << "full house" << endl;
		else if(straight) cout << "straight" << endl;
		else if(three) cout << "three card" << endl;
		else if(pair == 2) cout << "two pair" << endl;
		else if(pair == 1) cout << "one pair" << endl;
		else cout << "null" << endl;
	}
	return 0;
}