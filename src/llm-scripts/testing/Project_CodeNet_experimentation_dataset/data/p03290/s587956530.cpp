#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int d, g;
	cin >> d >> g;
	vector<pair<int,int>>pc(d);
	for (int i = 0; i < d; i++)cin >> pc.at(i).first >> pc.at(i).second;
	int ans = 1e10;
	for (int bit = 0; bit < (1 << d); bit++) {
		vector<pair<int, int>>pcc = pc;
		vector<int> l(0);
		for (int i = 0; i < d; i++) if (bit & (1 << i))l.push_back(i);
		int res = 0;
		int point = 0;
		for (int i = 0; i < l.size(); i++) {
			point += pcc.at(l.at(i)).second;
			res += pcc.at(l.at(i)).first;
			point += pcc.at(l.at(i)).first * (l.at(i) + 1) * 100;
			pcc.at(l.at(i)).first = 0;
		}
		int ct = d - 1;
		while (true) {
			if (ct == -1)break;
			if (point >= g)break;
			if (pcc.at(ct).first == 0) {
				ct--;
			}
			else {
				pcc.at(ct).first--;
				res++;
				point += (ct + 1) * 100;
			}
		}
		ans = min(ans, res);
	}
	cout << ans << endl;
}