#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

typedef pair<double, string> P;
typedef pair<string, double> Q;

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		string plant;
		int p, a, b, c, d, e, f, s, m;
		int time;
		double kou;
		priority_queue<P> pq;
		for (int i = 0; i < n; i++) {
			cin >> plant >> p >> a >> b >> c >> d >> e >> f >> s >> m;
			time = a+b+c+(d+e)*m;
			kou = (double)(s*f*m-p) / (double)time;
			P pp;
			pp.first = kou;
			pp.second = plant;
			pq.push(pp);
		}
		while (!pq.empty()) {
			P ppp = pq.top();
			pq.pop();
			priority_queue< Q, vector<Q>, greater<Q> > pqq;
			Q q;
			q.first = ppp.second;
			q.second = ppp.first;
			pqq.push(q);
			while (!pq.empty()) {
				if ((pq.top()).first == ppp.first) {
					q.first = (pq.top()).second;
					pqq.push(q);
					pq.pop();
				} else {
					break;
				}
			}
			while (!pqq.empty()) {
				cout << (pqq.top()).first << endl;
				pqq.pop();
			}
		}
		cout << '#' << endl;
	}
	return 0;
}