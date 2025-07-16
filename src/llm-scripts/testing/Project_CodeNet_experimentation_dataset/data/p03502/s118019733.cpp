#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,i;
	int sum = 0;
	int d = 10000000;
	int a,b,c;
	int x;
	cin >> n;
	
	
	for(i = 0 ; i < 8 ; i++)
	{
		a = d*10;
		b = n/a;
		c = b*10;
		sum += n/d - c ;
		d /= 10;
	}
	x = n/sum;
	if (sum != 0 && x*sum == n)
	cout << "Yes" << endl;
	
	else 
	cout << "No" << endl;
	
	

}