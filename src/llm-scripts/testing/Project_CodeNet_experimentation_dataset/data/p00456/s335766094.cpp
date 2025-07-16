// Aizu Vol-5 0533: Contest
// 2017.8.30 bal4u@uu

#include <stdio.h>

int max[2][3];

int main()
{
	int i, j, p, s[2];

	for (j = 0; j < 2; j++) {
		for (i = 0; i < 10; i++) {
			scanf("%d", &p);
			if      (p > max[j][0]) max[j][2] = max[j][1], max[j][1] = max[j][0], max[j][0] = p;
			else if (p > max[j][1]) max[j][2] = max[j][1], max[j][1] = p;
			else if (p > max[j][2]) max[j][2] = p;
		}
		for (s[j] = i = 0; i < 3; i++) s[j] += max[j][i];
	}
	printf("%d %d\n", s[0], s[1]);
	return 0;
}