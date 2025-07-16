#include <bits/stdc++.h>
using namespace std;
int N, A[1000000], cnt;

void Out(const vector<int> G) {
	cout << G.size() << endl;
	cout << G.back();
	for (int i = G.size() - 2; i >= 0; i--) {
		cout << ' ' << G[i];
	}
	cout << endl;
	cout << cnt << endl;
	for (int i = 0; i < N; i++)
		cout << A[i] << endl;
}

void InsertionSort(int g) {
	for (int i = g; i < N; i++) {
		int v = A[i], j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j -= g;
			cnt++;
		}
		A[j + g] = v;
	}
}
void ShellSort(const vector<int> G) {
	cnt = 0;
	for (int i = G.size() - 1; i >= 0; i--) {
		InsertionSort(G[i]);
	}
}

int main()
{
	vector<int> G;
	cin >> N;
	int calc = 1;
	while (calc <= N) {
		G.push_back(calc);
		calc = calc * 3 + 1;
	}
	for (int i = 0; i < N; i++)
		cin >> A[i];
	ShellSort(G);
	Out(G);
	return 0;
}