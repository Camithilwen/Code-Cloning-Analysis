#include<bits/stdc++.h>
#define L long long
#define pb push_back
#define pi pair<int,int>
#define pii pair<pair<int,int>,int>
#define aa first
#define bb second
#define xx aa.aa
#define yy aa.bb
#define zz bb
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
using namespace std;
int n;
L p,q;
inline void dfs(L x,L n,L m)
{
	//cout<<x<<" "<<n<<" "<<m<<"\n";
	if(x==0)
	  {
	   if(!n)
	     p+=m;
	   return;
	  }
	if(x==1)
	  {
	   if(!n)
	     p+=m*10;
	   return;
	  }
	int k=(10-n%10)%10;
	dfs(x/100,abs(n-k*x+k)/10,m*(10-abs(k)-(x==q)));
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(L k=1;k<=100000000000000000ll;k*=10)
	  q=k,dfs(k,n,1);
	printf("%lld\n",p);
	return 0;
}
