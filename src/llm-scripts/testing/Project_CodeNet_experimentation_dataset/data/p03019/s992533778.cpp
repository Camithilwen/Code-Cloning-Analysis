#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define MOD 1000000007LL
#define ROD 1000000000
#define INF 12345678
#define MIN(a,b) (a>b?b:a)
using namespace std;
#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define mp make_pair
#define  piii pair<pair<ll,ll>,pair <ll,ll>>
#define pii pair <ll,ll>
#define fi first
#define se second
ll ch(ll);
ll n,cr[100005],tot,x;
piii br[100005];
int main()
{
	cin>>n>>x;
	rep(i,0,n)
	{
		cin>>br[i].fi.se>>br[i].se.fi>>br[i].se.se;
		br[i].fi.fi=(br[i].se.se)*(x-br[i].fi.se)+br[i].fi.se*br[i].se.fi;
		tot+=br[i].fi.se*br[i].se.fi;
	}
	//cout<<tot<<"\n";
	sort(br,br+n,greater <piii> ());
	rep(i,0,n)
	{
		cr[i]=br[i].fi.fi;
		if(i-1>=0)
		cr[i]+=cr[i-1];
	}
	cr[n]=cr[n-1];
	// rep(i,0,n+1)
	// cout<<cr[i]<<" ";
	// rep(i,0,n)
	// cout<<br[i].fi.se<<" "<<br[i].se.fi<<" "<<br[i].se.se<<" "<<cr[i]<<"\n";
	ch(2497);
	ll low=0,high=n*x,mid,ans;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(ch(mid))
		{
			ans=mid;
			high=mid-1;
		}
		else
			low=mid+1;
	}
	//cout<<ch(400)<<" ";
	cout<<ans;
}
ll ch(ll mid)
{
	ll q=mid/x,r=mid-x*q;
	if(mid==n*x)
		return 1;
	//cout<<r<<" ";
	rep(i,0,n)
	{
		ll temp=0;
		if(i<q)
		{
			if(q>=0)
			temp+=cr[q]-br[i].fi.fi;
			//temp+=(r>br[i].fi.se?r*br[i].se.se:r*br[i].se.fi);
			temp+=(r>br[i].fi.se?(r-br[i].fi.se)*br[i].se.se+br[i].fi.se*br[i].se.fi:r*br[i].se.fi);		
		}
		else
		{
			if(q-1>=0)
			temp+=cr[q-1];
			temp+=(r>br[i].fi.se?(r-br[i].fi.se)*br[i].se.se+br[i].fi.se*br[i].se.fi:r*br[i].se.fi);		
			//cout<<"HERE"<<br[i].fi.se<<" "<<r<<" "<<r-br[i].fi.se<<" "<<br[i].se.se<<" ";
		}
		// ll qw=r>br[i].fi.se?(r-br[i].fi.se)*br[i].se.se+br[i].fi.se*br[i].se.fi:r*br[i].se.fi;
		// cout<<mid<<" "<<tot<<" "<<qw<<" "<<r<<" "<<" "<<temp<<"\n";
		if(temp>=tot)
			return 1;
	}
	return 0;
}