/*      Welcome to my Code      */

#include <bits/stdc++.h>
#define ll                      long long int
#define i(a,n)                  int a=n;
#define l(a,n)                  ll a=n;
#define d(a,n)                  double a=n;
#define s(a)                    string a;
#define c(a)                    ll a; cin>>a;a
#define cd(a)                   double a; cin>>a;
#define cs(a)                   string a; cin>>a;
#define ci(a)                   cin>>a;
#define co(a)                   cout<<a;
#define cos(a)                  cout<<a<<" ";
#define con(a)                  cout<<a<<endl;
#define yes                     cout<<"YES"<<endl
#define no                      cout<<"NO"<<endl
#define nl                      cout<<endl;
#define ca(arr,n)               for(ll i=0;i<n;i++) cin>>arr[i];
#define f0(i,a,n)               for(ll i=a;i>=n;i--)
#define f(i,n)                  for(ll i=0;i<n;i++)
#define f1(i,a,n)               for(ll i=a;i<n;i++)
#define lcm(a,b)                (a*b)/__gcd(a,b)
#define T                       ll t=1; cin>>t; while(t--)
#define fast                    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ret(x)                  return cout<<x,0;

using namespace std;

using namespace std;

int n;
long long ans;
long long num[25][25];
int main()
{
	cin>>n;
	while(n--)
	{
		double t;
		cin>>t;
		long long a=t*1e9+0.5;
		int n2=1,n5=1;
		while(a%2==0)
		{
			a/=2;
			n2++;
		}
		while(a%5==0)
		{
			a/=5;
			n5++;
		}
		n2=min(19,n2);
		n5=min(19,n5);
		f1(i,20-n2,20) f1(j,20-n5,20) ans+=num[i][j];
		num[n2][n5]++;
	}
	cout<<ans<<endl;
	return 0;
}

/*It's not who I am underneath, but what I do that defines me

MMMMMMMMMMMMMMMMMMMMM.                             MMMMMMMMMMMMMMMMMMMMM
 `MMMMMMMMMMMMMMMMMMMM           M\  /M           MMMMMMMMMMMMMMMMMMMM'
   `MMMMMMMMMMMMMMMMMMM          MMMMMM          MMMMMMMMMMMMMMMMMMM'
     MMMMMMMMMMMMMMMMMMM-_______MMMMMMMM_______-MMMMMMMMMMMMMMMMMMM
      MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
      MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
      MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
     .MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.
    MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
                   `MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM'
                          `MMMMMMMMMMMMMMMMMM'
                              `MMMMMMMMMM'
                                 MMMMMM
                                  MMMM
                                   MM
*/
