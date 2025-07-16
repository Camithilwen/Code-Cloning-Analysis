#include <iostream>
#include <map>

using namespace std;

void solve()
{
	int a[5];
	while(~scanf("%d,%d,%d,%d,%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]))
	{
		map<int, int> Map;
		for(int i = 0; i < 5; ++i)
		{
			++Map[a[i]];
		}
		if(Map.size() == 2)
		{
			int Max = 0;
			for(map<int, int>::iterator Ite = Map.begin(); Ite != Map.end(); ++Ite)
			{
				if(Max < Ite->second)
				{
					Max = Ite->second;
				}
			}
			if(Max == 3)
			{
				cout << "full house" << endl;
			}
			else
			{
				cout << "four card" << endl;
			}
		}
		else if(Map.size() == 3)
		{
			int Max = 0;
			for(map<int, int>::iterator Ite = Map.begin(); Ite != Map.end(); ++Ite)
			{
				if(Max < Ite->second)
				{
					Max = Ite->second;
				}
			}
			if(Max == 3)
			{
				cout << "three card" << endl;
			}
			else
			{
				cout << "two pair" << endl;
			}
		}
		else if(Map.size() == 4)
		{
			cout << "one pair" << endl;
		}
		else
		{
			map<int, int>::iterator Ite = Map.begin();
			map<int, int>::iterator IteNext = Map.begin();
			++IteNext;
			map<int, int>::iterator IteEnd = Map.end();
			IteEnd--;
			if(IteEnd->first - Ite->first == 4 || IteNext->first - Ite->first == 9)
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

int main()
{
	solve();
	return(0);
}