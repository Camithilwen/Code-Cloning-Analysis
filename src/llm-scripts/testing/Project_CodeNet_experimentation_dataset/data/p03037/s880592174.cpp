#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> L(M), R(M);
	for (int i = 0; i < M; i++) {
		cin >> L[i] >> R[i];
	}

	int lmax = *max_element(L.begin(), L.end());
	int rmin = *min_element(R.begin(), R.end());
	int d = rmin - lmax + 1;
	if (d < 0)
		d = 0;
	cout << d << endl;

	return 0;
}