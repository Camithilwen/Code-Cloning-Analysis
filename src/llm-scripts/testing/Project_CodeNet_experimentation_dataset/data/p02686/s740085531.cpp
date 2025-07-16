#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

char buf[1000010];

bool cmp(pii a, pii b) {
	return max(-a.se, -a.fi - b.se) < max(-b.se, -b.fi - a.se);
}

int main () {
	int n; scanf("%d", &n);
	int tot = 0;
	vector <pii> p, q;
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		int len = strlen(buf);
		int sum = 0, minj = 0;
		for (int i = 0; i < len; i++) {
			sum += buf[i] == '(' ? 1 : -1;
			minj = min(minj, sum);
		}
		tot += sum;
		if (sum >= 0) p.push_back(mp(minj, sum));
		else q.push_back(mp(sum, minj));
	}
	if (tot != 0) {
		printf("No\n");
		return 0;
	}
	sort(p.begin(), p.end());
	int sum = 0;
	while (p.size() && p.back().fi + sum >= 0) {
		sum += p.back().se;
		p.pop_back();
	}
	if (p.size()) {
		printf("No\n");
		return 0;
	}
	sort(q.begin(), q.end(), cmp);
	for (int i = 0; i < q.size(); i++) {
		if (sum + q[i].se < 0) {
			printf("No\n");
			return 0;
		}
		sum += q[i].fi;
	}
	printf("Yes\n");
	return 0;
}
