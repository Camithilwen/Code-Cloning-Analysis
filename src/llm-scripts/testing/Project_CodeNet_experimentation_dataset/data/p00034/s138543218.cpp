#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	string s;
	for (; getline(cin, s); )
	{
		stringstream ss;
		ss << s;

		vector<int> l(10);
		int v0, v1;

		for (int i = 0; i < 10; i++)
		{
			ss >> l.at(i);
			ss.ignore();

			l.at(i) *= 1000;
		}

		int d0 = 0;
		int d1 = accumulate(l.begin(), l.end(), 0);

		ss >> v0;
		ss.ignore();

		ss >> v1;

		for (; d0 < d1;)
		{
			d0 += v0;
			d1 -= v1;
		}

		int ll = 0;
		int x = 0;
		for (int i = 0; i < 10; i++)
		{
			ll += l.at(i);
			if (ll >= d0)
			{
				x = i + 1;
				break;
			}
		}

		cout << x << endl;
	}
}
