#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<double> v(N);
	for (int i = 0; i < N ; ++i)
		cin >> v[i];

	double roll = 0;
	for (int i = 0; i < K; ++ i)
		roll += 0.5 * (1. + v[i]);

	double maxima = roll;

	for (int i = 0; i < v.size() - K; ++i)
	{
		// cout << "subtract " << i << " " << v[i] << " add " << i + K << " " << v[i + K] << "\n";
	       	roll = roll + 0.5 * (1 + v[i + K]) - 0.5 * (1 + v[i]); 	
		maxima = max(maxima, roll);
	}
	printf("%.12f", maxima);

	return 0;
}
