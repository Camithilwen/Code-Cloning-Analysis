#include <iostream>
#include <math.h>
using namespace std;
int insertionSort(int, int, int);
void shellSort(int* , int);
int cnt = 0;
int main(void)
{
	int A[1000000], N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	shellSort(A, N);
}
int insertionSort(int A[], int n, int g)
{
	int v, j, cnt = 0;
	for (int i = g; i < n; i++) {
		v = A[i];
		j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
	return (cnt);
}
void shellSort(int A[], int n)
{
	int cnt = 0;
	int m = 0;
	int G[13] = {  };
	do {
		if (m == 0) { G[0] = n - 1; }
		else { G[m] = G[m - 1] / 2; }
		m++;
	} while (G[m - 1] > 1);
	cout << m << endl;
	for (int i = 0; i < m; i++) {
		cnt += insertionSort(A, n, G[i]);
		cout << G[i] << " ";
	}
	cout << endl << cnt << endl;
	for (int i = 0; i < n; i++) {
		cout << A[i] << endl;
	}
}