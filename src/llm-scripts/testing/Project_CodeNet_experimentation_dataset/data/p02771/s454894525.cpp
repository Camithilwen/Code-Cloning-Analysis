#include <bits/stdc++.h>
typedef long long ll;
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define rf(i,a,b) for(ll i=a; i>=b; i--)
typedef std::vector<long long > vi ;
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define PB push_back
#define MP make_pair
#define PI 3.14159265358979323846
#define all(a) a.begin(),a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define endl '\n'
#define show(a) for(auto el:a)cout<<el<<" "
const ll INF=LLONG_MAX/2;
const ll N=2e5+1;
#define yesno(f) yes(f);no(f);
#define yes(f) if(f)cout<<"YES\n";
#define no(f) if(!f)cout<<"NO\n";
using  namespace std;
ll pow1(ll n,ll p)
{
	if(p==0)	return 1;
	ll x=pow1(n, p/2);
	x=(x*x);
	if(p%2==0)
		return x;
	else
		return (x*n);
}
int main()
{
    fast;
   ll t=1;
    //std::cin >> t;
   while(t--)
   {
       ll n,w,x=0,sum=0,a,b,c;
       std::cin >> a>>b>>c;
       if(a==b&&b!=c)
       {
           cout<<"Yes\n";
       }
       else if(a==c&&a!=b)
       {
           cout<<"Yes\n";
       }
       else if(b==c&&a!=b)
       {
           cout<<"Yes\n";
       }
       else
       cout<<"No\n";
   }
}