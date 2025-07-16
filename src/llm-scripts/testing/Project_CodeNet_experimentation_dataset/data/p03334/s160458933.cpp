#include<bits/stdc++.h>
using namespace std;
int vis[1010][1010];
inline vector<pair<int,int> > getdistant(int n,int D1,bool hasret=true)
{
	int cnt[2]={0,0};
	vector<pair<int,int> > ret,trans;
	for(int i=0;i<n;i++)
	{
		int v=round(sqrt(D1-i*i));
		if(v*v+i*i==D1)trans.push_back(make_pair(i,v)),trans.push_back(make_pair(i,-v)),trans.push_back(make_pair(-i,v)),trans.push_back(make_pair(-i,-v));
	}
	memset(vis,255,sizeof(vis));
	queue<pair<int,int> > q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(vis[i][j]==-1)
			{
				// puts("----");
				q.push(make_pair(i,j));
				vis[i][j]=0;
				while(!q.empty())
				{
					pair<int,int> fr=q.front();q.pop();
					// printf("%d %d\n",fr.first,fr.second);
					for(auto &x:trans)
					{
						int nx=fr.first+x.first,ny=fr.second+x.second;
						if(nx>=0&&nx<n&&ny>=0&&ny<n&&vis[nx][ny]==-1)
						{
							vis[nx][ny]=vis[fr.first][fr.second]^1;
							q.push(make_pair(nx,ny));
						}
					}
				}
			}
		}
	}
	if(!hasret)return ret;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cnt[vis[i][j]]++;
		}
	}
	if(cnt[0]>cnt[1])
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(vis[i][j]==0)ret.push_back(make_pair(i,j));
			}
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(vis[i][j]==1)ret.push_back(make_pair(i,j));
			}
		}
	}
	return ret;
}
int vis2[1010][1010];
inline vector<pair<int,int> > solve(int n,int d1,int d2)
{
	vector<pair<int,int> > ret;
	if(n==1)
	{
		ret.push_back(make_pair(0,0));
		return ret;
	}
	if(d1%4&&d2%4)
	{
		for(int i=0;i<n;i+=2)
		{
			for(int j=0;j<n;j+=2)
			{
				ret.push_back(make_pair(i,j));
			}
		}
		return ret;
	}
	if(d2%4==0)swap(d1,d2);
	if(d2%4)
	{
		auto p=getdistant(n/2,d1/4);
		if(d2%4==2)
		{
			for(auto &x:p)
			{
				ret.push_back(make_pair(x.first*2,x.second*2));
				ret.push_back(make_pair(x.first*2,x.second*2+1));
			}
		}
		else
		{
			for(auto &x:p)
			{
				ret.push_back(make_pair(x.first*2,x.second*2));
				ret.push_back(make_pair(x.first*2+1,x.second*2+1));
			}
		}
		return ret;
	}
	else
	{
		getdistant(n,d2,0);
		memcpy(vis2,vis,sizeof(vis));
		getdistant(n,d1,0);
		int cnt[4]={0,0,0,0};
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cnt[vis[i][j]*2+vis2[i][j]]++;
			}
		}
		int mx=0;
		for(int i=1;i<=3;i++)if(cnt[i]>cnt[mx])mx=i;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(vis[i][j]*2+vis2[i][j]==mx)ret.push_back(make_pair(i,j));
			}
		}
		return ret;
	}
}
int n,D1,D2;
int main()
{
	scanf("%d%d%d",&n,&D1,&D2);
	auto ans=solve(n<<1,D1,D2);
	ans.resize(n*n);
	for(auto &p:ans)printf("%d %d\n",p.first,p.second);
	return 0;
}