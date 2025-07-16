#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e6+18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=500001;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound

ll k1=0;
bool comp(pair<ll,ll>a,pair<ll,ll>b)
{
	k1=max(k1,abs(a.ff-b.ff)+abs(a.ss-b.ss));
	if(a.ff>b.ff)
		return 1;

	if(a.ff==b.ff&&a.ss>b.ss)
		return 1;
	return 0;
}
int dx[]={1,-1};
int dy[]={1,-1};
int main()
{
	fastio;
	int t;
	ll i,j,k,n,m,l;
	cin>>n>>k>>l;
	if(k*l>=n)
		cout<<"Yes";
	else
		cout<<"No";

}
//Lordvishnu@almighty