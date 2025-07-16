#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	int c;
	int sum = 0;
	cin >> a >> b;
	c = a;
	for (int i= 0; i < b-a+1; i++)
	{
		if (c/10000 == c-(c/10)*10 && c/1000 - (c/10000)*10 == c/10 - (c/100)*10 )
		{	
		sum += 1;
		c++;
		continue;
		}
		
		else
		{
			c++;
			continue;
		}
		 
	}
	cout << sum << endl;
}