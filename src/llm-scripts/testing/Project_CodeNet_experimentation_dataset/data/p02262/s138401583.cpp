#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void insertionSort(vector<int> &a, int g, long &cnt)
{
	int j;
	int v;
	for (int i = g; i < a.size(); i++)
	{
		v = a[i];
		j = i - g;
		while (j >= 0 && a[j] > v)
		{
			a[j + g] = a[j];
			j = j - g;
			cnt++;
			if (cnt > (int)pow(a.size(), 1.5))
			{
				return;
			}
		}
		a[j + g] = v;
	}
}

int shellSort(vector<int> &a, vector<int> &g)
{
	long cnt = 0;
	for (int i = 0; i < g.size(); i++)
	{
		insertionSort(a, g[i], cnt);
		if (cnt > (int)pow(a.size(), 1.5))
		{
			break;
		}
	}
	return cnt;
}

int main()
{
	int n;
	long cnt = 0;
	cin >> n;
	vector<int> a(n, 0);
	vector<int> org(a);
	vector<int> g;
	for (int i = 0; i < n; i++)
	{
		cin >> org[i];
	}
	for (int m = 100; m >= 1; m--)
	{
		a = org;
		g.resize(m);
		g[m - 1] = 1;
		for (int i = 1; i < m; i++)
		{
			g[m - 1 - i] = 3 * g[m - i] + 1;
			if ((g[m - 1 - i] <= 0) || (n <= g[m - 1 - i]))
			{
				g[0] = -1;
				break;
			}
		}
		if (g[0] < 0)
		{
			continue;
		}
		else
		{
			cnt = shellSort(a, g);
			if (cnt <= pow(n, 1.5))
			{
				break;
			}
		}
	}
	cout << setprecision(10) << g.size() << endl;
	for (int i = 0; i < g.size(); i++)
	{
		cout << g[i];
		if (i == g.size() - 1)
		{
			cout << endl;
		}
		else
		{
			cout << " ";
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}
