#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int base[3] = {0, 0, 0};

void Hit()
{
	if (base[2] == 1)
	{
		base[2] = 0;
	}
	if (base[1] == 1)
	{
		base[2] = 1;
	}
	if (base[0] == 1)
	{
		base[1] = 1;
	}
	else if (base[0] == 0)
	{
		base[0] = 1;
	}

}

void Homerun()
{
	for (int i = 0; i < 3; i++)
	{
		base[i] = 0;
	}
	
}

int main()
{
	int out = 0;
    int score = 0;
	int n;
	string s;
    vector <string> event;
	int eventnum = 0;

	cin >> n;
	int a = 0;
	for (int i = 0; i < 3 * n; i++)
	{
		while (true)
		{
			cin >> s;
			event.push_back(s);
			if (event.at(a) == "OUT")
			{
				a += 1;			
				eventnum += 1;
				break;
			}
			else
			{
				a += 1;
				eventnum += 1;
			}

		}
	}

	for (int i = 0; i < eventnum; i++)
	{
		if (event.at(i) == "HIT")
		{
			if (base[2] == 1)
			{
				score += 1;
			}
			Hit();
		}
		else if (event.at(i) == "HOMERUN")
		{
			score += base[0] + base[1] + base[2] + 1;
			Homerun();
		}
		else
		{
			out += 1;
			if (out == 3)
			{
				cout << score << endl;
				for (int i = 0; i < 3; i++)
				{
					base[i] = 0;
				}
				score = 0;
				out = 0;
			}
		}
	}

	return 0;
}