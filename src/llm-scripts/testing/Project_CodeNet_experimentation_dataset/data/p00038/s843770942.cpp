#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <iostream>


using namespace std;


int c[5];
int counts[14];
int countscounts[5];

bool IsFourCard()
{
	return countscounts[4] == 1;
}
bool IsFullHouse()
{
	return countscounts[3] == 1 && countscounts[2] == 1;
}
bool IsStraight()
{
	for (int i = 0; i < 4; ++i)
	{
		if (c[i]+1 != c[i+1])
		{
			int t[] = { 1, 10, 11, 12, 13 };
			for (int j = 0; j < 5; ++j)
			{
				if (c[j] != t[j])
					return false;
			}
			return true;
		}
	}
	return true;
}
bool IsThreeCard()
{
	return countscounts[3] == 1;
}
bool IsTwoPair()
{
	return countscounts[2] == 2;
}
bool IsOnePair()
{
	return countscounts[2] == 1;
}
bool IsNull()
{
	return true;
}

int main()
{
	bool (*judge[])() = { IsFourCard, IsFullHouse, IsStraight
		, IsThreeCard, IsTwoPair, IsOnePair, IsNull };
	char* names[] = { "four card", "full house", "straight"
		, "three card", "two pair", "one pair", "null" };

	while (scanf("%d,%d,%d,%d,%d", c, c+1, c+2, c+3, c+4) != EOF)
	{
		sort(c, c+5);
		memset(counts, 0, sizeof(counts));
		memset(countscounts, 0, sizeof(countscounts));
		for (int i = 0; i < 5; ++i)
			++counts[c[i]];
		for (int i = 1; i < 14; ++i)
			++countscounts[counts[i]];

		for (int i = 0; i < sizeof(judge)/sizeof(judge[0]); ++i)
		{
			if (judge[i]())
			{
				puts(names[i]);
				break;
			}
		}
	}
	return 0;
}