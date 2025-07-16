#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
	int n;
	LLI a, b, x, diff, sum = 0 ;
	cin >> n >> x;
	cin >> a >> b;
	if( a + b > x )
	{
		diff = a + b - x;
		if( diff <= b )
	    	b -= diff;
	    else
	    	b = 0;
		sum += diff;
	}
	a = b;
	for(int i = 2; i < n; i++)
	{
	    cin >> b;
	    if( a + b > x )
		{
			diff = a + b - x;
			if( diff <= b )
		    	b -= diff;
		    else
		    	b = 0;
			sum += diff;
		}
		a = b;
	}
	cout << sum;
}
    