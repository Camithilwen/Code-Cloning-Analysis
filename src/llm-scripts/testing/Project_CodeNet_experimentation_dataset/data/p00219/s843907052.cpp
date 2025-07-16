#include <iostream>
using namespace std;

int main()
{
	int n,t;
	while(cin >> n, n)
	{
		int k[10] = {0};
		while(n--)
		{
			cin >> t;
			k[t]++;
		}

		for(int i=0; i<10; i++)
		{
			if(k[i])
			{
				for(int j=0; j<k[i]; j++)
				{
					cout << '*';
				}
				cout << endl;
			}
			else
			{
				cout << '-' << endl;
			}
		}
	}
}