#include<bits/stdc++.h>
#define MOD 1000000007
#define mp make_pair
#define ll long long
#define pb push_back
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug cout<<"Debugging.."<<endl
using namespace std;
int main()
{
	faster;

	ll int tc=1;
	while(tc--)
	{
		ll int n;
		cin>>n;
		 string s;
        while(n)
        {
            s+='a'+(n-1)%26;
            n=(n-1)/26;
        }
        reverse(s.begin(),s.end());
        cout<<s<<endl;

	}
}


