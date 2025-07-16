#include<iostream>
using namespace std;
#include<string>
#include<strstream>
#include<sstream>
#include<algorithm>
#include<math.h>
bool issqr(int n)
{
	double d = sqrt(n);
	double x = floor(d);
	if (d - x == 0)
		return true;
	else
		return false;
}
int main()
{
	int n; cin >> n;
	
	for (int i = n; i >= 0; --i)
	{
		if (issqr(i) == true)
		{
			cout << i;
			break;
		}
	}
}
