#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
	LLI n, a, b, save;
	cin >> n >> a >> b;
	
	LLI first, second, ans = 0;
	cin >> first >> second;
	save = ( second - first ) * a;
	if( save > b )
	    ans += b;
	else
	    ans += save;
	first = second;
	
	for(int i = 2; i < n; i++)
	{
		cin >> second;
	    save = ( second - first ) * a;
		if( save > b )
	    	ans += b;
	 	else
	    	ans += save;
		first = second;
	}
	cout << ans;
}