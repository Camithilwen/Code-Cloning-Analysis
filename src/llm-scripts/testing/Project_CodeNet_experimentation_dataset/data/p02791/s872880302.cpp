#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	int n, minNum = 1010101, ans = 0;
	cin >> n;

	rep(i, n)
	{
		int x;
		cin >> x;
		if (x <= minNum) ans++;		// 入力値より前の値以下であれば条件を満たす
		minNum = min(x, minNum);	// その時点での最大値更新
	}
	cout << ans << endl;
}