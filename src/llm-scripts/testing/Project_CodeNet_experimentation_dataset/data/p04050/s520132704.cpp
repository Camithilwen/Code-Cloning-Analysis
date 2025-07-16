#include <bits/stdc++.h>
using namespace std;

int A[103], B[103], cnt;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &A[i]);
		cnt += (A[i] & 1);
	}
	if(cnt > 2) return puts("Impossible"), 0;
	if(m == 1 && A[1] == 1) return printf("1\n1\n1\n"), 0;
	if(m == 1) return printf("%d\n2\n%d 1\n", A[1], A[1] - 1), 0;
	sort(A + 1, A + 1 + m, [](int x, int y) { return (x & 1) > (y & 1); });
	swap(A[2], A[m]);
	for(int i = 1; i <= m; i++)
		printf("%d%c", A[i], " \n" [i == m]);
	printf("%d\n%d ", A[m] > 1 ? m : m - 1, A[1] + 1);
	for(int i = 2; i < m; i++)
		printf("%d ", A[i]);
	if(A[m] > 1) printf("%d\n", A[m] - 1);
	return 0;
}
