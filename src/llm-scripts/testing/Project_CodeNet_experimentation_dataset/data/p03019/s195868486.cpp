#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <string>
#include <cmath>
#include <cassert>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

ll B[SIZE],L[SIZE],U[SIZE];
P pos[SIZE];

int main()
{
	int n;
	ll X;
	scanf("%d %lld",&n,&X);
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld %lld %lld",&B[i],&L[i],&U[i]);
		pos[i]=P((X-B[i])*U[i]+B[i]*L[i],i);
		sum-=B[i]*L[i];
	}
	sort(pos,pos+n);
	ll ret=0;
	int last=0;
	for(int i=n-1;i>=0;i--)
	{
		P p=pos[i];
		if(sum+p.first>=0)
		{
			ret+=(ll) (n-i-1)*(ll) X;
			last=i+1;
			break;
		}
		sum+=p.first;
	}
  // cout<<ret<<" "<<last<<endl;
	ll mn=X;
	sum=-sum;
  // cout<<sum<<endl;
	for(int i=0;i<last;i++)
	{
		int v=pos[i].second;
		mn=min(mn,(sum+L[v]-1)/L[v]);
		ll nsum=sum+B[v]*(U[v]-L[v]);
		mn=min(mn,(nsum+U[v]-1)/U[v]);
	}
	for(int i=last;i<n;i++)
	{
		int v=pos[i].second;
		ll nsum=sum+pos[i].first-pos[last-1].first;
		mn=min(mn,(nsum+L[v]-1)/L[v]);
		ll nsum2=nsum+B[v]*(U[v]-L[v]);
		mn=min(mn,(nsum2+U[v]-1)/U[v]);
	}
	printf("%lld\n",ret+mn);
	return 0;
}
