#include<bits/stdc++.h>
#define ll long long int
#define vl vector<ll>
#define pl pair<ll,ll>
#define pb push_back
#define F first
#define S second
using namespace std;
ll tako(ll a,ll b)
{
	if(a>=b)
      return 1;
  return 1+tako(a,b-a+1);
}
int main()
{
	ll a,b;
	cin >> a >> b;
	if(b==1)
	cout << "0";
	else
	cout << tako(a,b);
	
	return 0;
}