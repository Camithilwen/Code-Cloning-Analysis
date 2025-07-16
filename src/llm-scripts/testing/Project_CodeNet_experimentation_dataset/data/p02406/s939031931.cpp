
#include<iostream>
using namespace std;

void checknum(int &i, int &n);

void endchecknum(int i, int n)
{
	i++;
	if (i <= n)
	{
		checknum(i, n);
	}
	else
	{
		cout << endl;
	}
}

void include3(int &x, int &i, int &n)
{
	if (x % 10 == 3)
	{
		cout << " " << i;
		endchecknum(i, n);
	}
	else
	{
		x /= 10;
		if (x)
		{
			include3(x, i, n);
		}
		else
		{
			endchecknum(i, n);
		}
	}
}

void checknum(int &i, int &n)
{
	int x = i;

	if (x % 3 == 0)
	{
		cout << " " << i;
		endchecknum(i, n);
	}
	else
	{
		include3(x, i, n);
	}
}

void call(int &n)
{
	int i = 1;

	checknum(i, n);
}

int main()
{
	int n;

	cin >> n;
	call(n);
	return 0;
}