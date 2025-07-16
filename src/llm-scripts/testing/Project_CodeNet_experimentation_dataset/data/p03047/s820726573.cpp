#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <list>
#include <numeric>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
//================================================

int a = 0, b = 0, c, d, n, k=0;
string s, t;

long long kaizyou(int x)
{
	if (x == 1)
		return 1;
	else
		return x * kaizyou(x - 1);
}

int main()
{
	cin >> n >> k;
	cout << n-k+1 << endl;
	return 0;
}