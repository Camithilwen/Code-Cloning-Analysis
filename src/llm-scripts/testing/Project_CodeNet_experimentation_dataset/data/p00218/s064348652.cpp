#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

int n;

char student[10010];

double cal(int m,int e,int j)
{
	double ave = (double)(m + e + j) / 3;

	return ave;
}

int main(void)
{
	while (cin >> n, n)
	{
		for (int i = 0; i < n; i++)
		{
			int m, e, j;

			cin >> m >> e >> j;

			if (m==100||e==100||j==100)
			{
				student[i] = 'A';

				continue;
			}
			if (((double)(m+e)/2)>=90)
			{
				student[i] = 'A';

				continue;
			}

			if (cal(m,e,j)>=80)
			{
				student[i] = 'A';

				continue;
			}

			if (cal(m, e, j) >= 70)
			{
				student[i] = 'B';

				continue;
			}

			if (cal(m, e, j) >= 50)
			{
				if (m>=80||e>=80)
				{
					student[i] = 'B';

					continue;
				}
			}

			student[i] = 'C';

		}

		for (int i = 0; i < n; i++)
		{
			cout << student[i] << endl;
		}
	}
	
	return 0;
}
