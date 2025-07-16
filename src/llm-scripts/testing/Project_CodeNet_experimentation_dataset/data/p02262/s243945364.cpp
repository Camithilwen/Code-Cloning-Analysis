#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

namespace {

	int cnt;
	void InsertionSort(vector<int>& A, int g)
	{
		for (int i = g; i < A.size(); ++i)
		{
			int v = A[i];
			int j = i - g;

			while (j >= 0 && A[j] > v) {
				A[j + g] = A[j];
				j -= g;
				cnt++;
			}

			A[j + g] = v;
		}
	}

	void ShellSort(vector<int>& A)
	{
		int m;
		cnt = 0;
		vector<int> G;
		G.push_back(1);
		for (int i = 1; i <= A.size(); ++i)
		{
			int g = pow(4, i) + 3 * pow(2, i - 1) + 1;
			if (g <= A.size()) G.push_back(g);
			else { m = i; break; }
		}

		for (int i = m - 1; i >= 0; --i)
			InsertionSort(A, G[i]);

		cout << m << endl;
		for (int i = m - 1; i >= 0; --i) {
			cout << G[i];
			i != 0 ? cout << " " : cout << endl;
		}
		cout << cnt << endl;
		for (int i = 0; i < A.size(); ++i)
			cout << A[i] << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> A(n);
	for (int i = 0; i < n; ++i)
		cin >> A[i];

	ShellSort(A);

	return 0;
}