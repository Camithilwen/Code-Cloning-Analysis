	#include<bits/stdc++.h>
	#include<ext/pb_ds/assoc_container.hpp>
	#include<ext/pb_ds/tree_policy.hpp>
	#define pi 3.141592653589793238
	#define int long long
	using namespace __gnu_pbds;
	using namespace std;
	template <typename T>
	using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

	map<int,int>dis;

	map<int,vector<pair<int,int> > >mm;
	void bfs(int ver)
	{
		priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int>> >qq;
		qq.push({0,ver});
		while (!qq.empty())
		{
			pair<int,int>pp=qq.top();
			qq.pop();
			for(auto i:mm[pp.second])
			{
				if(dis[i.first]>pp.first+i.second)
				{
					dis[i.first]=pp.first+i.second;
					qq.push({dis[i.first],i.first});
				}
			}
		}	
	}

	signed main()
	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  
	cout.tie(0);   

	#ifndef ONLINE_JUDGE
		if(fopen("INPUT.txt","r"))
		{
		freopen ("INPUT.txt" , "r" , stdin);
		freopen ("OUTPUT.txt" , "w" , stdout);
		}
	#endif  

		int x,y;
		cin>>x>>y;
		mm[x].push_back({-x,1});
		mm[-x].push_back({x,1});
		mm[y].push_back({-y,1});
		mm[-y].push_back({y,1});
		int arr[4];
		arr[0]=x;
		arr[1]=-x;
		arr[2]=-y;
		arr[3]=y;
		for(int i=0;i<4;i++)
		{
			dis[arr[i]]=1e17;
			for(int j=0;j<4;j++)
			{
				if(arr[j]>arr[i])
					mm[arr[i]].push_back({arr[j],arr[j]-arr[i]});
			}
		}
		dis[x]=0;
		bfs(x);
		cout<<dis[y];

	}
