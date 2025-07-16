#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k; cin >> n >> k;
	vector<double> v(n);
	vector<double> expected(n);
	for(int i = 0; i < n; ++i) 
	{
		cin >> v[i];
		expected[i] = ((v[i]*(v[i]+1.0))/2.0)/v[i];
		
		if(i)
			expected[i] += expected[i-1];
		
	}
	double maxi = expected[k-1];
	double tolerance = 0.0000001;
	for(int i = k-1; i < n; ++i)
	{
		int pre = i - k;
		if(pre >= 0)
		{
			double cur = expected[i] - expected[pre];
			if(cur-maxi > tolerance)
				maxi = cur;
		}
	}

	cout << setprecision(17) <<  maxi;

	return 0;
	
}