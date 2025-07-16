#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define aa first
#define bb second
#define xx aa.aa
#define yy aa.bb
#define zz bb
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
using namespace std;
int n,m,p;
L f[600000],g[600000],q,ans;
inline void modify(L f[],int i,int j,int k,int x,L p)
{
	f[i]=min(f[i],p);
	if(j<k)
	  if(x<=(j+k>>1))
	    modify(f,i<<1,j,j+k>>1,x,p);
	  else
	    modify(f,i<<1|1,(j+k>>1)+1,k,x,p);
}
inline L minn(L f[],int i,int j,int k,int l,int r)
{
	if(l<=j && k<=r)
	  return f[i];
	else
	  {
	   L p=1e18;;
	   if(l<=(j+k>>1))
	     p=min(p,minn(f,i<<1,j,j+k>>1,l,r));
	   if(r>(j+k>>1))
	     p=min(p,minn(f,i<<1|1,(j+k>>1)+1,k,l,r));
	   return p;
	  }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	L k;
	scanf("%d%d",&n,&m);
	for(p=1;p<n;p<<=1);
	for(i=1;i<2*p;i++)
	  f[i]=g[i]=1e18;
	scanf("%d%d",&i,&j);
	modify(f,1,1,p,i,-i);
	modify(g,1,1,p,i,i);
	while(m--)
	  {
	   scanf("%d",&i);
	   q+=abs(i-j);
	   ans+=abs(i-j);
	   k=min(minn(f,1,1,p,1,i)+i,minn(g,1,1,p,i,n)-i)-abs(i-j);
	   modify(f,1,1,p,j,k-j);
	   modify(g,1,1,p,j,k+j);
	   ans=min(ans,q+k);
	   j=i;
	  }
	printf("%lld\n",ans);
	return 0;
}
