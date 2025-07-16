#include<iostream>

using namespace std;

struct ST{
	int a;
	int b;
	int c;

	int an;
};

int reset(int, int */*[100 + 10]*/);

int main()
{
	int ans[1000 + 10];

	ST res[1000 + 10];

	int an, bn, cn, n;

	int ml;

	int ln;

	int i, j;
	int af, bf, cf;

	while (cin >> an >> bn >> cn, an != 0 && bn != 0 && cn != 0)
	{
		cin >> n;

		ln = n;

		ml = an + bn + cn;

		reset(ml, ans);

		for (i = 1; i <= ln; i++)
		{
			cin >> res[i].a >> res[i].b >> res[i].c >> res[i].an;

			if (res[i].an == 1)
			{
				ans[res[i].a] = 1;
				ans[res[i].b] = 1;
				ans[res[i].c] = 1;

				i--;
				ln--;
			}
		}

		for (i = 1; i <= ln; i++)
		{
			af = bf = cf = 0;

			if (ans[res[i].a] == 1) af = 1;
			if (ans[res[i].b] == 1) bf = 1;
			if (ans[res[i].c] == 1) cf = 1;

			if (af + bf + cf == 2)
			{
				if (af == 0)
				{
					ans[res[i].a] = 0;
				}
				if (bf == 0)
				{
					ans[res[i].b] = 0;
				}
				if (cf == 0)
				{
					ans[res[i].c] = 0;
				}
			}
		}

		for (i = 1; i <= ml; i++)
		{
			cout << ans[i] << endl;
		}
	}

	return 0;
}

int reset(int n,int *le)
{
	int i;
	for (i = 0; i < n; i++)
	{
		le[i] = 2;
	}
	return 0;
}