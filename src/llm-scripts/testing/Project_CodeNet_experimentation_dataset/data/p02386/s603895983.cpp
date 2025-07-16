#include <iostream>
#define MEN 6
using namespace std;


struct IN_DICE
{
	int num1;
	int num2;
	int num3;
	int num4;
	int num5;
	int num6;
};

struct DICE
{
	int num;
};

int main()
{
	DICE A[MEN];
	DICE B1[MEN];
	DICE B2[MEN];
	DICE B3[MEN];

	IN_DICE in[100];
	int flag = 0;
	int x;
	int n;

	cin >> n;

	for ( int i = 0; i < n; i++)
	{
		cin >> in[i].num1 >> in[i].num2 >> in[i].num3 >> in[i].num4 >> in[i].num5 >> in[i].num6;
	}

	for (int i1 = 0; i1 < n - 1; i1++)
	{
		for (int i2 = i1 + 1; i2 < n; i2++)
		{
			A[0].num = in[i1].num1;
			A[1].num = in[i1].num2;
			A[2].num = in[i1].num3;
			A[3].num = in[i1].num4;
			A[4].num = in[i1].num5;
			A[5].num = in[i1].num6;

			B1[0].num = in[i2].num1;
			B1[1].num = in[i2].num2;
			B1[2].num = in[i2].num3;
			B1[3].num = in[i2].num4;
			B1[4].num = in[i2].num5;
			B1[5].num = in[i2].num6;

			for (int count = 0; count < MEN; count++)
			{
				for (int i = 0; i < MEN; i++)
				{
					B2[i] = B1[i];
				}
				if (1 <= count && count <= 5)
				{
					x = B2[0].num;
					B2[0].num = B2[1].num;
					B2[1].num = B2[5].num;
					B2[5].num = B2[4].num;
					B2[4].num = x;
				}

				if (2 <= count && count <= 4)
				{
					for (int i = 0; i < count - 1; i++)
					{
						x = B2[0].num;
						B2[0].num = B2[2].num;
						B2[2].num = B2[5].num;
						B2[5].num = B2[3].num;
						B2[3].num = x;
					}
				}

				if (count == 5)
				{
					x = B2[0].num;
					B2[0].num = B2[1].num;
					B2[1].num = B2[5].num;
					B2[5].num = B2[4].num;
					B2[4].num = x;
				}

				if (A[0].num != B2[0].num)
				{
					continue;
				}

				for (int i = 0; i < MEN; i++)
				{
					B3[i] = B2[i];
				}

				for (int count2 = 0; count2 < 4; count2++)
				{
					for (int i = 0; i < MEN; i++)
					{
						B2[i] = B3[i];
					}
					for (int i = 0; i < count2; i++)
					{
						x = B2[1].num;
						B2[1].num = B2[2].num;
						B2[2].num = B2[4].num;
						B2[4].num = B2[3].num;
						B2[3].num = x;
					}

					x = B2[0].num;
					B2[0].num = B2[1].num;
					B2[1].num = B2[5].num;
					B2[5].num = B2[4].num;
					B2[4].num = x;

					if (A[1].num != B2[0].num)
					{
						continue;
					}

					x = B2[0].num;
					B2[0].num = B2[2].num;
					B2[2].num = B2[5].num;
					B2[5].num = B2[3].num;
					B2[3].num = x;

					if (A[2].num != B2[0].num)
					{
						continue;
					}

					x = B2[0].num;
					B2[0].num = B2[2].num;
					B2[2].num = B2[5].num;
					B2[5].num = B2[3].num;
					B2[3].num = x;

					if (A[4].num != B2[0].num)
					{
						continue;
					}

					x = B2[0].num;
					B2[0].num = B2[2].num;
					B2[2].num = B2[5].num;
					B2[5].num = B2[3].num;
					B2[3].num = x;

					if (A[3].num != B2[0].num)
					{
						continue;
					}

					x = B2[0].num;
					B2[0].num = B2[1].num;
					B2[1].num = B2[5].num;
					B2[5].num = B2[4].num;
					B2[4].num = x;

					if (A[5].num == B2[0].num)
					{
						flag = 1;
					}
					if (flag == 1)
					{
						break;
					}
				}
				if (flag == 1)
				{
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}

	if (flag == 1)
	{
		cout << "No" << endl;
	}
	else if (flag == 0)
	{
		cout << "Yes" << endl;
	}

	return 0;
}