#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) (V).begin(),(V).end()
#define MOD 1000000007
#define mod 998244353

int rw[100010];
vector<int> W[100010];

int main(){
	for (int i = 0;i < 100010;i++)rw[i] = -1;
	ll N, L;
	cin >> N;
	vector<ll> X(N);
	for (int i = 0;i < N;i++)
		cin >> X[i];
	cin >> L;
	for (int j = 0;j < N;j++) {
		if (rw[j] >= 0)continue;
		for (int i = j;i < N;) {
			W[j].push_back(i);
			if (rw[i] >= 0)break;
			rw[i] = j;
			auto it = upper_bound(all(X), X[i] + L);
			it--;
			i = it - X.begin();
		}
	}

	//for (int i = 0;i < N;i++)cout << rw[i] << " ";

	ll Q, a, b, c, d, ans = 0;
	cin >> Q;
	for (int i = 0;i < Q;i++) {
		ans = 0;
		cin >> a >> b;
		if (a > b)swap(a, b);
		a--;b--;
		c = rw[a];
		while (1) {
			auto it = W[c].end();
			it--;
			d = *it;
			if (d >= b)break;
			ans += it - find(all(W[c]), a);
			//cout << ans << endl;
			a = d;
			c = rw[a];
		}
		auto it1 = find(all(W[c]), a);
		auto it2 = lower_bound(all(W[c]), b);
		ans += it2 - it1;
		cout << ans << endl;
	}
}