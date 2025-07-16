#include <iostream>
using namespace std;
int main()
{
	while (1)
	{
		int a = 0;
		int x = 0;
		int d = 0;
		int aa[10001];
		for (int i = 0; i < 10001; i++)
		{
			aa[i] = 0;
		}
		cin >> x;
		cin >> a;
		if (x == 0 && a == 0)
		{
			break;
		}
		int b[10000];
		int c[10000];
		for (int i = 0; i < a; i++)
		{
			cin >> b[i];
			cin >> c[i];
		}
		for (int i = 0; i < a; i++)
		{
			if (b[i] == 1)
			{
				aa[c[i]] = 1;
				for (int j = 0; j < a; j++)
				{
					if (c[i] == b[j])
					{
						aa[c[j]] = 1;
					}
					if (c[i] == c[j])
					{
						aa[b[j]] = 1;
					}
				}
			}
		}
		for (int i = 2; i <= x; i++)
		{
			if (aa[i] == 1)
			{
				d++;
			}
		}
		cout << d << endl;
	}
	
	return 0;
}