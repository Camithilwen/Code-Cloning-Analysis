#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int ac = 2e5 + 5, bc = (1 << 18);
ll PR[ac];
ll CS[ac];

struct Tree
{
	vector<ll> T;
	Tree()
	{
		T.resize(bc * 2);
	}
	void update(int a, ll b)
	{
		a += bc;
		T[a] = b;
		while (a)
		{
			a /= 2;
			T[a] = min(T[a * 2], T[a * 2 + 1]);
		}
	}
	ll query(int a, int b)
	{
		a += bc; b += bc;
		ll m = min(T[a], T[b]);
		while (a / 2 != b / 2)
		{
			if (a % 2 == 0) m = min(m, T[a + 1]);
			if (b % 2 == 1) m = min(m, T[b - 1]);
			a /= 2; b /= 2;
		}
		return m;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q, a, b; cin >> n >> q >> a >> b; a--; b--;
	vector<ll> Q; Q.push_back(a);
	for (int i = 0; i < q; i++) { int x; cin >> x; x--; Q.push_back(x); } 
	ll s = 0;
	for (int i = 1; i <= q; i++) CS[i] = abs(Q[i] - Q[i - 1]), s += CS[i];
	Tree t1, t2;
	for (int i = 0; i < n; i++) t1.update(i, (ll)1e12), t2.update(i, (ll)1e12);
	t1.update(b, b); t2.update(b, -b);
	for (int i = 1; i <= q; i++)
	{
		ll w = min(t2.query(0, Q[i]) + Q[i], t1.query(Q[i], n - 1) - Q[i]) - CS[i];
		if (w < t1.query(Q[i - 1], Q[i - 1]))
		{
			t1.update(Q[i - 1], w + Q[i - 1]);
			t2.update(Q[i - 1], w - Q[i - 1]);
		}
	}
	ll m = 1e18;
	for (int i = 0; i < n; i++)
		m = min(m, t1.query(i, i) - i);
	cout << m + s << '\n';
}
