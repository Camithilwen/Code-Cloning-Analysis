#include <iostream>
#include <math.h>

using namespace std;
void Solve(int a)
{
	const double pi = 3.14;
	float ans;
	ans = 2 * pi * a;
	cout << ans;
}
int main()
{
	int x;
	cin >> x;
	Solve(x);
	return 0;
}