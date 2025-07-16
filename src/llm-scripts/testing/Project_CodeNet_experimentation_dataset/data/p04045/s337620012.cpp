#include <bits/stdc++.h>
#include <string>
using namespace std;

vector<bool> d(10, true);

bool isvalid(int n)
{
	int dec = n % 10;
	if(!d[dec]) return false;
	if(n/10 != 0) return isvalid(n/10);
	return true;
}

int main()
{
	int k, n;
	cin >> n >> k;

	for (int i = 0; i < k; i++){
		int tmp; cin >> tmp;
		d[tmp] = false;
	}

	while(!isvalid(n)) n++;
	cout << n << '\n';
	return 0;
}