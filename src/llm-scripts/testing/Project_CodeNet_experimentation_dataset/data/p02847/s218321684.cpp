#if __has_include("debug.h")
    #include "debug.h"
#else  
#include <bits/stdc++.h>
using namespace std;
#define d(...) 2;
#endif

#define int long long int
#define ld long double

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"      

#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define ff first
#define ss second
#define eps 1e-10
#define PI acos(-1LL)

#define gcd(a,b)            __gcd((a),(b))
#define lcm(a,b)            ((a*b)/gcd(a,b))

void solve();

int32_t main()
{
    #ifdef DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif 

    fast
    
    int t = 1;
	// cin>>t;
	
	while(t--)
	    solve();
	return 0;  
}

void solve()
{
	int i,j;
	string s;
	cin>>s;

	vector<string>v{"MON","TUE","WED","THU","FRI","SAT","SUN"};

	int cnt=0;

	while(1)
	{
		for(i=0;i<v.size();i++)
		{
			if(v[i]==s)
			{
				j=(i+1)%7;
				cnt++;
				while(v[j]!="SUN")
				{
					cnt++;
						j=(j+1)%7;
				}
				cout<<cnt<<endl;
				return;
			}
		}
	}

}