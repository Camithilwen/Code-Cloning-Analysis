#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long n, x; cin >> n;
	x = int(sqrt(n));
	while (n%x) x--;
	cout << max(int(log10(x) + 1), int(log10(n/x) + 1)) << endl;
}

