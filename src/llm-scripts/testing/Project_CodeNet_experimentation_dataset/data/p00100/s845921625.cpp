#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;
typedef vector<int> vi;

int main() {
	int n;
	while (cin >> n, n) {
		ll data[4001] = {};
		bool uni[4001] = {};
		vi order;
		
		REP(i, n) {
			ll a, b, c;
			scanf("%lld %lld %lld", &a, &b, &c);
			if (!uni[a]) {
				uni[a] = true;
				order.push_back(a);
			}
			data[a] += b * c;
		}
		
		bool f = false;
		REP(i, order.size()) {
			int num = order[i];
			if (data[num] >= 1000000) {
				printf("%d\n", num);
				f = true;
			}
		}
		if (!f) puts("NA");
	}
	return 0;
}