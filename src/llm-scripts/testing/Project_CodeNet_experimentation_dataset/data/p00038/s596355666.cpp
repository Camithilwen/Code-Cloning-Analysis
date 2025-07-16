#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int cards[5], i, j, t, r, fl, fl2;
	char c, str[8][11] = {"null", "one pair", "two pair", "three card", "straight", "full house", "four card"};
	while (cin >> cards[0] >> c >> cards[1] >> c >> cards[2] >> c >> cards[3] >> c >> cards[4])
	{
		r = 1;
		sort(cards, cards+5);
		int n[13] = {0};
		for (i = 0; i < 5; i++)
			n[cards[i]-1]++;
		for (i = fl = t = 0; i < 13; i++)
			if (n[i] == 2)	t++;
		if (t == 1)	r = 2;
		if (t == 2)	r = 3;
		for (i = fl = 0; i < 13 && !fl; i++)
			if (n[i] == 3)	r = 4, fl = 1;
		for (i = fl = 0; i < 9 && !fl; i++)
		{
			for (j = 0, fl2 = 1; j < 5 && fl2; j++)
				if (n[i+j] != 1)	fl2 = 0;
			if (fl2)	r = 5, fl2 = 1;
		}
		if (!fl)
		{
			for (i = 9, fl = 0; i < 13 && !fl; i++)
				if (n[i] != 1)	fl = 1;
			if (!fl && n[0])	r = 5;
		}
		for (i = fl = fl2 = 0; i < 13; i++)
		{
			if (n[i] == 2)	fl = 1;
			if (n[i] == 3)	fl2 = 1;
		}
		if (fl && fl2)	r = 6;
		for (i = fl = 0; i < 13 && !fl; i++)
			if (n[i] == 4)
				r = 7, fl = 1;
		cout << str[r-1] << endl;
	}
}