#include<iostream>
using namespace std;

int main()
{
	int a, b, c,i,j;
	cin >> a >> b >> c;
	
	i = a;
	a = b;
	b = i;
	
	j = a;
	a = c;
	c = j;

	cout << a << " " << b << " " << c;
	return 0;
}