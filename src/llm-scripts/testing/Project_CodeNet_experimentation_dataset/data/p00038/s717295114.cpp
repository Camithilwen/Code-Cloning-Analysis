#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <utility>
#include <numeric>

using namespace std;
typedef long long llong;
typedef unsigned long long ullong;

const ullong MOD = 1000000000 + 7;

int main()
{
	string s;
	for (; cin >> s;)
	{
		vector<int> a(14);

		stringstream ss;
		ss << s;

		for (int i = 0; i < 5; i++)
		{
			int x;
			ss >> x;

			a.at(x - 1)++;
			if (x == 1)
			{
				a.at(13)++;
			}

			ss.ignore();
		}

		int maxn = 0;
		int cnt = 0;
		int len = 0;
		bool str = false;
		for (int i = 0; i < 14; i++)
		{
			if (a.at(i) > 0)
			{
				maxn = max(maxn, a.at(i));
				if (i < 13)
				{
					cnt++;
				}
				len++;
				if (len >= 5)
				{
					str = true;
				}
			}
			else
			{
				len = 0;
			}
			
		}

		if (maxn == 4)
		{
			cout << "four card" << endl;
		}
		else if (maxn == 3)
		{
			if (cnt == 2)
			{
				cout << "full house" << endl;
			}
			else
			{
				cout << "three card" << endl;
			}
		}
		else if (maxn == 2)
		{
			if (cnt == 3)
			{
				cout << "two pair" << endl;
			}
			else
			{
				cout << "one pair" << endl;
			}
		}
		else
		{
			if (str)
			{
				cout << "straight" << endl;
			}
			else
			{
				cout << "null" << endl;
			}
		}
	}
}

