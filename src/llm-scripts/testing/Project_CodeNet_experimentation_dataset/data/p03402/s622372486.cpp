#include <stdio.h>

char a[111][111];

int main(void)
{
	int W, B, n = 100, i, j;

	scanf("%d %d" ,&W, &B);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
            a[i][j] = (i <= n / 2 ? '.' : '#');

    for (i = 1; i <= (B - 1) / (n / 2); i++)
		for (j = 1; j <= n / 2; j++)
            a[i * 2 - 1][j * 2 - 1] = '#';
	for (j = 1; j <= (B - 1) % (n / 2); j++)
		a[i * 2 - 1][j * 2 - 1] = '#';

	for (i = 1; i <= (W - 1) / (n / 2); i++)
		for (j = 1; j <= n / 2; j++)
            a[(n + 1) - (i * 2 - 1)][j * 2 - 1] = '.';
	for (j = 1; j <= (W - 1) % (n / 2); j++)
		a[(n + 1) - (i * 2 - 1)][j * 2 - 1] = '.';

	puts("100 100");
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			printf("%c" ,a[i][j]);
		puts("");
	}
	return 0;
}