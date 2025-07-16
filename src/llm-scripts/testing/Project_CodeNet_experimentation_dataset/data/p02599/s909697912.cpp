#include<bits/stdc++.h>
using namespace std;
int n,t,a[505050],tr[505050],ans[505050],lt[505050];
vector<int>q[505050],qq[505050];
void gx(int x,int vl)
{
	while(x<=n)
	{
		tr[x]+=vl;
		x+=x&(-x);
	}
}
int sm(int x)
{
	int rt=0;
	while(x>0)
	{
		rt+=tr[x];
		x-=x&(-x);
	}
	return rt;
}
int main()
{
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=t;i++)
	{
		int l,r;
		cin>>l>>r;
		q[r].push_back(l);
		qq[r].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(lt[a[i]]!=0)
		{
			gx(lt[a[i]],-1);
		}
		lt[a[i]]=i;
		gx(i,1);
		for(int j=0;j<q[i].size();j++)
		{
			ans[qq[i][j]]=sm(i)-sm(q[i][j]-1);
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}