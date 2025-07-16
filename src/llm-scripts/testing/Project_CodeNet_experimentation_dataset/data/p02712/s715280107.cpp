#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	ll n;
	cin>>n;
	ll k,p,x,ans;
	ans = (n*(n+1))/2;
    k = n/3;
    p = n/5;
    x = n/15;
    ans = ans - 3*(k*(k+1)/2) - 5*(p*(p+1))/2 + 15*(x*(x+1))/2;
    cout<<ans<<endl;
}
int main()
{

  solve();

return 0;
}

