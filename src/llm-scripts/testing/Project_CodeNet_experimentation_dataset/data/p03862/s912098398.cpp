#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long int ll;
int main()
{
	int n;
	ll a, b, x, d, op = 0 ;
	cin >> n >> x;
	cin >> a >> b;
	if( a + b > x )
	{
		d = a + b - x;
		if( d <= b ){
	    	b -= d;
        }
	    else
        {
	    	b = 0;
        }
          op += d;
	}
	a = b;
	rep(i,2,n)
	{
	    cin >> b;
	    if( a + b > x )
		{
			d = a + b - x;
			if( d <= b ){
		    	b -= d;
            }
		    else
            {
              b = 0;
            }  
			op += d;
		}
		a = b;
	}
	cout << op<< endl;
	return 0;
}