#include <algorithm>
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int N;
	long long Y;
	cin >> N >> Y;
	int a, b , c;
	a = 0;
	while (a <= Y / 10000)
	{
		b = 0;
		while (10000*a + 5000 * b <= Y)
		{
			c = N - a - b;
			if (10000*a + 5000*b + 1000*c == Y)
			{	cout << a << " " << b << " " << c << endl;
				return 0;
			}
			b++;
		}
		a++;
	}
	cout << "-1 -1 -1" << endl;
	return 0;
}