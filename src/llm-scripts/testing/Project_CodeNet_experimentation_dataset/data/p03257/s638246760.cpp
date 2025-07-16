#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=505;
const int M=4*N;
const int S=10000;
int pr[M],psz;
bool sieve[S];
ll val[N][N];
vector<pair<int,int> > id;
int Find(pair<int,int> x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
int main()
{
	int i,j;
	for(i=2;i<S;i++) if(!sieve[i]){ pr[++psz]=i;for(j=i;j<S;j+=i) sieve[j]=1;}
	int n;
	scanf("%i",&n);
	if(n==2) return 0*printf("4 7\n23 10\n");
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if((i+j)&1)
	{
		int a=i+j,b=i-j;
		id.pb(mp(1,a));
		id.pb(mp(2,b));
	}
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if((i+j)&1)
	{
        int a=Find(mp(1,i+j));
        int b=Find(mp(2,i-j));
        val[i][j]=(ll)pr[a]*pr[b];
	}
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) if(!((i+j)&1))
	{
		val[i][j]=1;
		if(i-1>0 || j+1<=n) val[i][j]*=pr[Find(mp(2,i-j-1))];
		if(i+1<=n || j-1>0) val[i][j]*=pr[Find(mp(2,i-j+1))];
		if(i-1>0 || j-1>0) val[i][j]*=pr[Find(mp(1,i+j-1))];
		if(i+1<=n || j+1<=n) val[i][j]*=pr[Find(mp(1,i+j+1))];
		val[i][j]++;
	}
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) printf("%lld%c",val[i][j],j==n?'\n':' ');
	return 0;
}