#include <bits/stdc++.h>
typedef  long double ll;
#define fr(i,a,b) for(long long i=a; i<b; i++)
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
int main()
{
    fast;
   ll t;
   t=1;
   while(t--)
   {
       long long n,x=0,k;
       std::cin >> n>>k;
       ll a[n],maxi=0,sum;
       fr(i,0,n)
       std::cin >> a[i];
       fr(i,0,k)
       maxi+=((a[i]+1)/2);
       sum=maxi;
       fr(i,k,n)
       {
           sum=sum-((a[i-k]+1)/2)+(a[i]+1)/2;
           maxi=max(maxi,sum);
       }
       cout<<fixed;
       cout<<setprecision(12);
       cout<<maxi<<"\n";
       
   }
}