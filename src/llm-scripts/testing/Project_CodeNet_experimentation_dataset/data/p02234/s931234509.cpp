#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, i, j, l,k;
	int A[101];
	int q[101][101];
	cin >> n;
	for (i = 1; i < n+1; i++) {
		cin >> A[i - 1] >> A[i];
	}
	for (i = 0; i < n + 1; i++) q[i][i] = 0;

	for (l = 2; l < n + 1; l++) {
		for (i = 1; i < n - l + 2; i++) {
			j = i + l - 1;
			q[i][j] = (1<<21);
			for (k = i; k < j; k++) {
				q[i][j] = min(q[i][j], q[i][k] + q[k + 1][j] + A[i - 1] * A[k] * A[j]);
			}
		}
	}
	cout << q[1][n] << endl;

}