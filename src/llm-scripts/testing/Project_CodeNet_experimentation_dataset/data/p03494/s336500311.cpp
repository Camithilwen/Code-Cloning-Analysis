#include <iostream>
#include <vector>

using namespace std;

int powerOf2(int n)	{
	int res = 0;
	while (n % 2 == 0)	{
		res++;
		n /= 2;
	}
	return res;
}

int main()	{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)	{
		cin >> a[i];
	}
	int pow2 = 1e9;
	for (int i = 0; i < n; i++)	{
		pow2 = min(pow2, powerOf2(a[i]));
	}	
	cout << pow2 << endl;
	return 0;
}
