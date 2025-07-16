#include<iostream>
using namespace std;
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define int long long int
int function2(int memo[],int turn[],int n,map<int,int> &sticks)
{
	if(n<0)
	{
		return -1000000000;
	}
	if(n==0)
	{
		return 0;
	}
	if(memo[n]!=-1)
	{
		return memo[n];
	}
	else
	{
		map<int,set<int>> mp;
		int here=-1000000000;
		mp[here].insert(-1);
		for(auto &p:sticks)
		{
			int val=1+function2(memo,turn,n-p.second,sticks);
			mp[val].insert(p.first);
		}
		auto it=mp.end();
		it--;
		int answer=*it->second.rbegin();
		turn[n]=answer;
		memo[n]=it->first;
		return it->first;
	}
}
int32_t main()
{
	int n,m;
	cin>>n>>m;
	int value[10]={0,2,5,5,4,5,6,3,7,6};
	map<int,int> sticks;
	int j;
	for(j=0;j<m;j++)
	{
		int x;
		cin>>x;
	    sticks.insert({x,value[x]});
	}
	int memo[n+1],turn[n+1];
	for(j=0;j<=n;j++)
	{
		memo[j]=-1;
		turn[j]=-1;
	}
	int val=function2(memo,turn,n,sticks);
	while(n!=0)
	{
		int here=turn[n];
		cout<<here;
		n-=value[here];
	}
	cout<<endl;
}
