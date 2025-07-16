#include <cstdio>
#include <cstring>

#define MAX_N 105

int N, A, B, C, D, S[MAX_N + 1];

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < (N * N - N) / 2; i++)
	{
		scanf("%d", &A);
		scanf("%d", &B);
		scanf("%d", &C);
		scanf("%d", &D);

		if (C > D) { S[A] += 3; }
		if (C < D) { S[B] += 3; }
		if (C == D) { S[A] += 1; S[B] += 1; }
	}

	int rank;

	for (int i = 1; i <= N; i++)
	{
		rank = 1;

		for (int j = 1; j <= N; j++)
		{
			if (S[i] < S[j]) { rank += 1; }
		}

		printf("%d\n", rank);
	}

	return 0;
}