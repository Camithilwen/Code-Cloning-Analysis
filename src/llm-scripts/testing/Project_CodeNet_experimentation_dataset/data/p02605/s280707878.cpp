#include <bits/stdc++.h> 
using namespace std;
const int N = 200005;
int n, x[N], y[N], ansd = INT_MAX;
char d[N]; 
void solvelr()
{
	vector<int> a[N], b[N];
	for (int i = 0; i < n; ++i)
	{
		if (d[i] == 'L')
			a[y[i]].push_back(x[i]);
		else if (d[i] == 'R')
			b[y[i]].push_back(x[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		sort(a[i].begin(), a[i].end());
		sort(b[i].begin(), b[i].end());
	}
	for (int i = 0; i < N; ++i)
	{
		for (int xc: b[i])
		{
			auto it = upper_bound(a[i].begin(), a[i].end(), xc);
			if (it == a[i].end())
				continue;
			else
			{
				int d = *it - xc;
				d *= 5;
				ansd = min(ansd, d);
			}
		}
	}
}
void solveud()
{
	vector<int> a[N], b[N];
	for (int i = 0; i < n; ++i)
	{
		if (d[i] == 'U')
			a[x[i]].push_back(y[i]);
		else if (d[i] == 'D')
			b[x[i]].push_back(y[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		sort(a[i].begin(), a[i].end());
		sort(b[i].begin(), b[i].end());
	}
	for (int i = 0; i < N; ++i)
	{
		for (int yc: a[i])
		{
			auto it = upper_bound(b[i].begin(), b[i].end(), yc);
			if (it == b[i].end())
				continue;
			else
			{
				int d = *it - yc;
				d *= 5;
				ansd = min(ansd, d);
			}
		}
	}
}
bool cmp(pair<int, int> lhs, pair<int, int> rhs)
{
	return lhs.first < rhs.first;
}
void solve1()
{
	vector<pair<int, int> > a[2 * N];
	for (int i = 0; i < n; ++i)
	{
		int dif = x[i] - y[i];
		a[dif + 200000].push_back(make_pair(x[i], d[i]));
	}
	for (int i = 0; i < 2 * N; ++i)
	{
		int l = -1, r = -1, u = -1, d = -1;
		sort(a[i].begin(), a[i].end(), cmp);
		for (pair<int, int> p: a[i])
		{
			if (p.second == 'L')
			{
				if (u != -1)
					ansd = min(ansd, 10 * (p.first - u));
				l = p.first;
			}
			else if (p.second == 'R')
				r = p.first;
			else if (p.second == 'U')
				u = p.first;
			else if (p.second == 'D')
			{
				if (r != -1)
					ansd = min(ansd, 10 * (p.first - r));
				d = p.first;
			}
		}
	}
}
void solve2()
{
	vector<pair<int, int> > a[2 * N];
	for (int i = 0; i < n; ++i)
	{
		int dif = x[i] + y[i];
		a[dif].push_back(make_pair(x[i], d[i]));
	}
	for (int i = 0; i < 2 * N; ++i)
	{
		int l = -1, r = -1, u = -1, d = -1;
		sort(a[i].begin(), a[i].end(), cmp);
		for (pair<int, int> p: a[i])
		{
			if (p.second == 'L')
			{
				if (d != -1)
					ansd = min(ansd, 10 * (p.first - d));
				l = p.first;
			}
			else if (p.second == 'R')
				r = p.first;
			else if (p.second == 'U')
			{
				if (r != -1)
					ansd = min(ansd, 10 * (p.first - r));
				u = p.first;
			}
			else
				d = p.first;
		}

	}
}
int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i] >> d[i];
	}
	solvelr();
	solveud();
	solve1();
	solve2();
	if (ansd == INT_MAX)
		cout << "SAFE" << '\n';
	else
		cout << ansd << '\n';
	return 0;
}