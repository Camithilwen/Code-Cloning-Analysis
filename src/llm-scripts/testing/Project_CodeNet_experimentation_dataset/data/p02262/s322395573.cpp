#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

int cnt = 0;
vector<int> g;

void insertionSort(vector<int> &a, int g)
{
	for (int i = g; i < a.size(); i++)
	{
		int v = a[i];
		int j = i - g;
		for (; j >= 0 && a[j] > v;)
		{
			a[j + g] = a[j];
			j -= g;
			cnt++;
		}
		a[j + g] = v;
	}
}

void shellSort(vector<int> &a)
{
	for (int i = 1; i <= a.size(); i = 3 * i + 1)
	{
		g.push_back(i);
	}

	for (int i = g.size() - 1; i >= 0; i--)
	{
		insertionSort(a, g.at(i));
	}
}

int main()
{
	int n;
	vector<int> a;
	for (cin >> n; n--;)
	{
		int x;
		cin >> x;

		a.push_back(x);
	}

	shellSort(a);

	cout << g.size() << endl;
	for (int i = g.size() - 1; i >= 0; i--)
	{
		cout << g.at(i) << (i == 0 ? "" : " ");
	}

	cout << endl;
	cout << cnt << endl;

	for (int i = 0; i < a.size(); i++)
	{
		cout << a.at(i) << endl;
	}
}
