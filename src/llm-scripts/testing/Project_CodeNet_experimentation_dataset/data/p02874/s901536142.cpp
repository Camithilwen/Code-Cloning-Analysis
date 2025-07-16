#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

struct problem {
	ll l, r;
	problem() = default;
	problem(ll a, ll b) { l = a, r = b; }
};

int N;
problem pr[100000 + 100];

ll a[100000 + 10] = {}, b[100000 + 10] = {};


int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> pr[i].l >> pr[i].r;

	sort(pr, pr + N, [](problem a, problem b) {
		if (a.l != b.l)return a.l < b.l;
		else return a.r > b.r;
	});

	int p = 0, q = 0;//pは再左端のrを持つ区間番号　qは再右端のlを持つ区間番号
	for (int i = 1; i < N; i++) {
		if (pr[p].r > pr[i].r)p = i;
	}
	for (int i = 1; i < N; i++) {
		if (pr[q].l < pr[i].l)q = i;
	}
	ll ans = 0;
	
	//pとqを1つの集合に入れる
	ans += max(0LL, pr[p].r - pr[q].l + 1);
	ll largest = 0;
	for (int i = 0; i < N; i++) {
		if (i == p || i == q)continue;
		largest = max(largest, pr[i].r - pr[i].l + 1);
	}
	ans += largest;

	//pとqを別々の集合に入れる。a[i] := i個p以外を含んで、その時点での結果
	a[0] = pr[p].r - pr[p].l;
	ll m = pr[p].l;
	for (int i = 1; i <= N; i++) {
		m = max(m, pr[i - 1].l);
		a[i] = max(0LL, pr[p].r - m + 1);
	}

	b[0] = pr[q].r - pr[q].l;
	ll M = pr[q].r;
	for (int i = 1; i <= N; i++) {
		M = min(M, pr[N - i].r);
		b[i] = max(0LL, M - pr[q].l + 1);
	}
	
	for (int i = 0; i <= N; i++)ans = max(ans, a[i] + b[N - i]);
	cout << ans << endl;

	return 0;
}