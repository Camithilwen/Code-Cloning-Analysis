#include <cstdio>
#include <algorithm>
using namespace std;

char S[1001001];
int D[10], F[10];

int main()
{
	scanf ("%s", S);
	for (int i = 0; i < 10; i++) D[i] = i;

	for (int t = 0; S[t]; t++){
		for (int j = 0; j < 10; j++) F[j] = 1e9;
		for (int j = 0; j < 10; j++) for (int i = 0; i < 10; i++){
			int k = j * 10 + i - (S[t] - '0');
			if (k < 0) continue;
			int c = i + k / 10;
			k %= 10;
			if (F[k] > D[j] + c)
				F[k] = D[j] + c;
		}
		for (int j = 0; j < 10; j++) D[j] = F[j];
	}

	int ans = 1e9;
	for (int j = 0; j < 10; j++) if (ans > D[j] + j) ans = D[j] + j;
	printf ("%d\n", ans);
	return 0;
}
