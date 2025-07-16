#include <iostream>

using namespace std;

int main ()
{
	int a[100],b[100],a1,a2,a3,b1;

	a1 = 0;
	a2 = 0;
	a3 = 0;
	b1 = 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
	}
	for (int j = 0; j < 2; j++)
	{
		cin >> b[j];
	}

	for (int i = 0; i < 4; i++)
	{
		if (a[i] >= a1)
		{
			a3 = 0;
			a3 = a2;
			a2 = 0;
			a2 = a1;
			a1 = 0;
			a1 = a[i];
		}
		else if (a[i] >= a2)
		{
			a3 = 0;
			a3 = a2;
			a2 = 0;
			a2 = a[i];
		}
		else if (a[i] >= a3)
		{
			a3 = 0;
			a3 = a[i];
		}
	}
	for (int j = 0; j < 2; j++)
	{
		if (b1 < b[j])
		{
			b1 = 0;
			b1 = b[j];
		}
	}

	cout << a1 + a2 + a3 + b1 << endl;
}