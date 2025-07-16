#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <class Type> Type GCD(Type a, Type b)
{
	if (a % b == 0) { return b; }
	if (b % a == 0) { return a; }

	if (a > b) { return GCD(b, a % b); }
	if (a < b) { return GCD(a, b % a); }

	return (Type)(-1);
}

template <class Type> Type GCD(vector<Type> v)
{
	Type ret = v[0];

	for (int i = 1; i < v.size(); i++)
	{
		ret = GCD(ret, v[i]);
	}

	return ret;
}

template <class Type> vector<Type> Divisors(Type n)
{
	vector<int> c;

	for (Type i = 1; i * i <= n; i++)
	{
		if (n % i == 0) { c.push_back(i); if (i * i != n) { c.push_back(n / i); } }
	}

	sort(c.begin(), c.end());

	return c;
}

int main()
{
	int n;

	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	vector<int> c = Divisors(GCD(v));

	for (int i = 0; i < c.size(); i++)
	{
		cout << c[i] << endl;
	}

	return 0;
}