#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#include<map>
#include<set>
using namespace std;
int g[100005];
int F(int x)
{
	return g[x]==x?g[x]:g[x]=F(g[x]);
}
void U(int x,int y)
{
	g[F(x)]=F(y);
}
int n;
pair <pair<int,int>,int> a[100005];
vector <pair<int,pair<int,int> > > v;
long long ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].first.first,&a[i].first.second);
		a[i].second=i;
		g[i]=i;
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
	    v.push_back(make_pair(a[i+1].first.first-a[i].first.first,
		make_pair(a[i].second,a[i+1].second)));
	for(int i=0;i<n;i++)
	    swap(a[i].first.first,a[i].first.second);
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
	    v.push_back(make_pair(a[i+1].first.first-a[i].first.first,
		make_pair(a[i].second,a[i+1].second)));
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		int k22=v[i].second.second;
		int k21=v[i].second.first;
		//cout<<v[i].first<<' '<<k21<<' '<<k22<<endl;
		int aaa=F(k21),bbb=F(k22);
		//cout<<k21<<':'<<aaa<<' '<<k22<<':'<<bbb<<endl;
		if(aaa==bbb)
		    ;
		else
	    {
	    	//cout<<aaa<<' '<<bbb<<endl;
	    	U(k21,k22);
	    	ans+=v[i].first;
	    	//cout<<v[i].first<<endl;
		}
	}	    
	cout<<ans;
	return 0;
}