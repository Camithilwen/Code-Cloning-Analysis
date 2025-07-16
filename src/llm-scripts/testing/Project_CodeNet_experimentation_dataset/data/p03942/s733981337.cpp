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

const int maxn = 1e6 + 100, maxc = 256;
const ll inf = 2e18, mod = 1e9 + 7;

int n, pos[maxc], R[maxn], dest[maxn], par[maxn], fen[maxn * 2];
char s[maxn], t[maxn];
vector<int> vec[maxc];

void update(int x, int val)
{
	for (int ind = x + 1; ind < maxn * 2; ind += (ind & -ind))
		fen[ind] += val;
}

int query(int x)
{
	int res = 0;
	for (int ind = x + 1; ind; ind -= (ind & -ind))
		res += fen[ind];
	return res;
}

bool check(int H)
{
	memset(fen, 0, sizeof(fen));
	update(n, -H);
	update(0, H);

	int cut = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (query(cut + i) == 0)
			return false;
		if (!i || t[i] != t[i - 1])
		{
			if (query(cut + i) < H)
				cut++;
			else
			{
				update(cut + i, -H);
				update(cut + i + 1, H);
			}
			update(par[i] + cut, -1);
			update(i + cut, 1);
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < maxc; i++)
		pos[i] = -mod;

	cin >> n >> s >> t;

	if (strcmp(s, t) == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	int ind = 0;
	for (int i = 0; i < n; i++)
		if (t[i] != t[i - 1])
		{
			for (int j = ind; j < i; j++)
				R[j] = i - 1;
			ind = i;
		}
	for (int i = ind; i < n; i++)
		R[i] = n - 1;

	for (int i = 0; i < n; i++)
		vec[s[i]].pb(i);
	ind = n;
	for (int i = n - 1; i >= 0; i--)
	{
		while (ind - 1 > i)
		{
			ind--;
			//cerr << "ERASE " << t[ind] << endl;
			vec[s[ind]].popb();
		}
		if (!i || t[i] != t[i - 1])
		{
			if (vec[t[i]].empty())
			{
				//cerr << '#' << i << ' ' << t[i] << ' ' << ind << endl;
				cout << -1 << endl;
				return 0;
			}
			par[i] = vec[t[i]].back();
			for (int j = vec[t[i]].back(); j < ind; j++)
				vec[s[j]].popb();
			ind = par[i];
		}
	}
	for (int i = 0; i < n; i++)
		if (!i || t[i] != t[i - 1])
			for (int j = i; j <= R[i]; j++)
				par[j] = par[i];
	//for (int i = 0; i < n; i++)
	//	cerr << '_' << par[i];
	//cerr << endl;
	for (int i = 0; i < n; i++)
		if ((i && par[i] < par[i - 1]) || par[i] > i)
		{
			//cerr << "QUIT " << i << ' ' << par[i] << endl;
			cout << -1 << endl;
			return 0;
		}

	/*while (true)
	{
		int x;
		cin >> x;
		cerr << '#' << check(x) << endl;
	}*/
	int l = 0, r = n + 100, mid;
	while (r - l > 1)
	{
		mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	
	cout << r << endl;
}

