#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		string dec = s;
		while (true)
		{
			if (dec.find("the") != -1 || dec.find("this") != -1 || dec.find("that") != -1)
			{
				cout << dec << endl;
				break;
			}
			for (int i = 0; i < dec.size(); i++)
			{
				if ('a' <= dec[i] && dec[i] < 'z') dec[i]++;
				else if (dec[i] == 'z') dec[i] = 'a';
			}
		}
	}

	return 0;
}