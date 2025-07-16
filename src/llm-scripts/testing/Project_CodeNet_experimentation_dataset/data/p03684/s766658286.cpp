/******************
*  Author: BD747  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

#define MP make_pair

int r[100005];

int FIND(int x){
	return (x==r[x]) ? x : (r[x]=FIND(r[x]));
}

int n;
long long ans;
vector<pair<int,pair<int,int> > > v;
pair<pair<int,int>,int> g[100005];
int cnt;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for(int i=0;i<=100000;i++){
		r[i]=i;
	}
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>g[i].first.first>>g[i].first.second;
		g[i].second=i;
	}
	sort(g,g+n);
	for(int i=0;i<n-1;i++){
		int x1=g[i].first.first,y1=g[i].first.second,id1=g[i].second;
		int x2=g[i+1].first.first,y2=g[i+1].first.second,id2=g[i+1].second;
		v.push_back(MP( min(abs(x1-x2),abs(y1-y2)) , MP(id1,id2)));
		g[i].first.first=y1;g[i].first.second=x1;
	}
	int x=g[n-1].first.first,y=g[n-1].first.second;
	g[n-1].first.first=y;
	g[n-1].first.second=x;
	sort(g,g+n);
	for(int i=0;i<n-1;i++){
		int x1=g[i].first.first,y1=g[i].first.second,id1=g[i].second;
		int x2=g[i+1].first.first,y2=g[i+1].first.second,id2=g[i+1].second;
		v.push_back(MP( min(abs(x1-x2),abs(y1-y2)) , MP(id1,id2)));
	}
	sort(v.begin(),v.end());
	//cout<<pq.size()<<endl;
	for(int i=0;i<v.size();i++){
		int id1=v[i].second.first,id2=v[i].second.second,len=v[i].first;
		if( !(FIND(id1)==FIND(id2)) ){
			ans+=((long long)len);
			r[FIND(id1)]=FIND(id2);
			cnt++;
		}
		if(cnt>=n-1){
			break;
		}
	}
	cout<<ans<<endl;

	return 0;
}
