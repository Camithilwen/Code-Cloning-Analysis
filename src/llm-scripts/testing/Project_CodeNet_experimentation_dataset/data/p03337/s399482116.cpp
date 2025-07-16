#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int a, b, ma;
	cin >> a >> b;
	ma = max(a + b, a - b);
	ma = max(ma, a * b);
	cout << ma << endl;
} 