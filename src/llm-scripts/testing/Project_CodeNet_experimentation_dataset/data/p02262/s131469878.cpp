#include<iostream>
using namespace std;


 int InsertionSort(int* a, int n, int g)
{
	int tmp, j, count = 0;
	for (int i = g; i < n; i++)
	{
		tmp = a[i];
		for (j = i - g; j >= 0 && a[j] > tmp; j -= g)
		{
			a[j + g] = a[j];
			count++;
		}
		a[j + g] = tmp;
	}
	return count;
}

int ShellSort(int* a, int n)
{
	int m, g[100],count = 0;
	for (m = 1; m * m * m <= n; m++)
		continue;
	m--;
	cout << m << endl;
	for (int i = 0; i < m; i++)
	{
	    g[i] = (m - i) * (m - i);
		if (i)
			cout << " ";
		cout << g[i];
	}
	for (int i = 0; i < m; i++)
		count += InsertionSort(a, n, g[i]);

	return count;
}

int main()
{
	int n, a[1000000], count;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	count = ShellSort(a, n);
	cout << endl << count << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;

	return 0;
}
