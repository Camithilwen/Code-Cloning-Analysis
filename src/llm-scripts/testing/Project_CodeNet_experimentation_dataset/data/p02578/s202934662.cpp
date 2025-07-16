#include<bits/stdc++.h>                                                   //---------------------------------------------------------------

# define ll long long
# define mod 1000000007
# define MAX 100005
# define PI 3.141592653589793238                                                                                  //shortcut keys

# define pb push_back
# define mp make_pair
# define all(x) x.begin(),x.end()
# define fr(i,a,b) for(int i=a;i<=b;i++)

# define decimal(k) fixed<<setprecision(k)
# define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);        //---------------------------------------------------------------
using namespace std;

int main()
{
	int n;cin>>n;
	ll a[n+1],b[n+1];
	fr(i,1,n)cin>>a[i];
	b[1]=a[1];
	fr(i,2,n){
		if(a[i]>=b[i-1]){
			b[i]=a[i];
		}
		else b[i]=b[i-1];
	}
	//fr(i,1,n)cout<<b[i]<<' ';
	ll ans=0;
	fr(i,1,n)ans+=b[i]-a[i];
	cout<<ans<<'\n';

	return 0;
}

