#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(),v.end()

const int maxn = 1e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

int n, a[maxn];

bool bad()
{
	for (int i = 0; i < n; i++)
		if (a[i] != 1)
			return false;
	return true;
}

void solve(int turn = 0)
{
	if (bad())
	{
		cout << ((1 - turn) ? "Second" : "First") << endl;
		return;
	}
	int parity = 0;
	bool check = false;
	for (int i = 0; i < n; i++)
		parity ^= (a[i] & 1), check |= (a[i] == 1);
	if (check)
	{
		if (parity ^ (n & 1))
			cout << (turn ? "Second" : "First") << endl;
		else
			cout << ((1 - turn) ? "Second" : "First") << endl;
		return;
	}
	if (n & 1)
	{
		if (!parity)
		{
			cout << (turn ? "Second" : "First") << endl;
			return;
		}
		else
		{
			int cnt = 0;
			for (int i = 0; i < n; i++)
				cnt += (a[i] & 1);
			if (cnt > 1)
			{
				cout << ((1 - turn) ? "Second" : "First") << endl;
				return;
			}
			else
			{
				for (int i = 0; i < n; i++)
					if (a[i] & 1)
						a[i]--;
				int GCD = a[0];
				for (int i = 1; i < n; i++)
					GCD = __gcd(a[i], GCD);
				for (int i = 0; i < n; i++)
					a[i] /= GCD;
				solve(1 - turn);
			}
		}
	}
	else
	{
		if (!parity)
			cout << ((1 - turn) ? "Second" : "First") << endl;
		else
			cout << (turn ? "Second" : "First") << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	solve();
}

