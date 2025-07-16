#include <bits/stdc++.h>
#define N 1000010
#define F first
#define S second
using namespace std;
int n,m,book[N],nd;
vector<pair<int,int> > ed[N];
vector<int> col[N],ng[N];
int main(){
	int x,y,c,i,j,k;
	//memset(book,-1,sizeof(book));
	cin>>n>>m;
	nd=n;
	for(i=0;i<m;i++)
	{
		cin>>x>>y>>c;
		x--;
		y--;
		ed[x].push_back(make_pair(c,y));
		ed[y].push_back(make_pair(c,x));
		col[c].push_back(x);
		col[c].push_back(y);
	}
	for(i=0;i<n;i++)
	{
		sort(ed[i].begin(),ed[i].end());
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<col[i].size();j++)
		{
			y=col[i][j];
			if(book[y]==i)
			{
				continue;
			}
			queue<int> q;
			q.push(y);
			book[y]=i;
			while(q.size())
			{
				x=q.front();
				q.pop();
				ng[x].push_back(nd);
				ng[nd].push_back(x);
				for(k=lower_bound(ed[x].begin(),ed[x].end(),make_pair(i,0))-ed[x].begin();k<ed[x].size();k++)
				{
					if(ed[x][k].F!=i)
					{
						break;
					}
					if(book[ed[x][k].S]!=i)
					{
						book[ed[x][k].S]=i;
						q.push(ed[x][k].S);
					}
				}
			}
			nd++;
		}
	}
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<ng[i].size();j++)
		{
			cout<<i<<"->"<<ng[i][j]<<endl;
		}
	}*/
	queue<int> q,st;
	q.push(0);
	st.push(0);
	book[0]=-2;
	while(q.size())
	{
		x=q.front();
		y=st.front();
		q.pop();
		st.pop();
		if(x==n-1)
		{
			cout<<y/2<<endl;
			return 0;
		}
		for(i=0;i<ng[x].size();i++)
		{
			c=ng[x][i];
			if(book[c]==-2)
			{
				continue;
			}
			book[c]=-2;
			q.push(c);
			st.push(y+1);
		}
	}
	cout<<-1<<endl;
	return 0;
}