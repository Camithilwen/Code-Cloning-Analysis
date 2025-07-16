#include <bits/stdc++.h>
using namespace std;
#define GOOD 1000000

long total[4005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, id, p, q, cnt;
	cin >> n;
	while (n != 0) {
		for (int i = 0; i < 4005; i++) {
			total[i] = 0;
		}
		cnt = 1;
		for (int i = 0; i < n; i++) {
			cin >> id >> p >> q;
			long before = total[id];
			total[id] += p * q;
			if (before < GOOD && total[id] >= GOOD) {
				cout << id << endl;
				cnt = 0;
			}
		}
		if  (cnt) {
			cout << "NA" << endl;
		}
		cin >> n;
	}
}
