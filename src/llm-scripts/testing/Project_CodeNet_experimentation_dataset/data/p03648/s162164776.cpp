//KING NIKAN
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll ans[60] ;
int main() 
{
	ios::sync_with_stdio(false) ;cin.tie(0) ;cout.tie(0) ;
	ll k ;
	cin >> k ;
	cout << 50 << "\n" ;
	ll x=k/50 ;
	for(int i=0 ;i<50 ;i++)
	{
        ans[i] = x+49;
    }
    ll y = k%50;
    for(int k=0 ;k<y ;k++)
	{
        for(int i=0 ;i<50 ;i++)
		{
            if(k==i) 
			{
				ans[i]+=50 ;	
			}
            else 
			{
				ans[i]-=1 ;	
			}
        }
    }
    for(int i=0 ;i<50 ;i++)
    {
    	cout << ans[i] << " " ;
	}
	return 0 ;
}