#include<iostream>
using namespace std;
int cnt = 0;
int n;
int a[1000000];
int w[500000];
int G[500000];
int m;
int shellsort();
int aho(int g);




int shellsort()
{
	m = n / 2;
	if (m == 0)
	{
		m = 1;
	}
	//cout << m << endl;
	for (int i = 0; i < m; i++)
	{
		if (i == 0)
		{
			G[0] = m;
		}
		else
			G[i] = G[i - 1] / 2;
		if (G[i] == 0)
		{
			m = i;
			break;
		}
		//cout << G[i];
		//if (i != m - 1)cout << " ";
	}
	cout << m << endl;
	for (int i = 0; i < m; i++)
	{
		cout << G[i];
		if (i != m - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		aho(G[i]);
	}
	return 0;
}
int aho(int g)
{
	for (int i = g; i < n; i++)
	{
		int v = a[i];
		int j = i - g;
		while (j>=0 && a[j] > v)
		{
			a[j + g] = a[j];
			j = j - g;
			cnt++;
		}
		a[j + g] = v;
	}
	return 0;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	shellsort();
	cout << cnt << endl;
	for (int i = 0; i < n; i++)
	{
	 cout << a[i] << endl;
	}

	




}