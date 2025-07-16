#include<stdio.h>
#include<string.h>

int main()
{
	int m,n, N;
	int dice[101][101];
	scanf("%d", &N);
	for (n = 0; n < N; n++)
	{
		for (m = 0; m < 6; m++)
		{
			scanf("%d", &dice[n][m]);
		}
	}
	int i = 4, tmp, j = 4;
	for (n = 0; n < N - 1; n++)
	{
		for (m = n + 1; m < N; m++)
		{
			while (i--)
			{
				if (dice[n][0] == dice[m][0]
					&& dice[n][1] == dice[m][1]
					&& dice[n][2] == dice[m][2]
					&& dice[n][3] == dice[m][3]
					&& dice[n][4] == dice[m][4]
					&& dice[n][5] == dice[m][5])
				{
					printf("No\n");
					return 0;
				}
				while (j--)
				{
					tmp = dice[n][1];
					dice[n][1] = dice[n][2];
					dice[n][2] = dice[n][4];
					dice[n][4] = dice[n][3];
					dice[n][3] = tmp;
					if (dice[n][0] == dice[m][0]
						&& dice[n][1] == dice[m][1]
						&& dice[n][2] == dice[m][2]
						&& dice[n][3] == dice[m][3]
						&& dice[n][4] == dice[m][4]
						&& dice[n][5] == dice[m][5])
					{
						printf("No\n");
						return 0;
					}
				}
				j = 4;
				if (i % 2 == 0)
				{
					tmp = dice[n][0];
					dice[n][0] = dice[n][1];
					dice[n][1] = dice[n][5];
					dice[n][5] = dice[n][4];
					dice[n][4] = tmp;
					if (dice[n][0] == dice[m][0]
						&& dice[n][1] == dice[m][1]
						&& dice[n][2] == dice[m][2]
						&& dice[n][3] == dice[m][3]
						&& dice[n][4] == dice[m][4]
						&& dice[n][5] == dice[m][5])
					{
						printf("No\n");
						return 0;
					}
				}
				if (i % 2 == 1)
				{
					tmp = dice[n][0];
					dice[n][0] = dice[n][2];
					dice[n][2] = dice[n][5];
					dice[n][5] = dice[n][3];
					dice[n][3] = tmp;
					if (dice[n][0] == dice[m][0]
						&& dice[n][1] == dice[m][1]
						&& dice[n][2] == dice[m][2]
						&& dice[n][3] == dice[m][3]
						&& dice[n][4] == dice[m][4]
						&& dice[n][5] == dice[m][5])
					{
						printf("No\n");
						return 0;
					}
				}
			}
			i = 4;
		}
	}

	printf("Yes\n");
	return 0;
}