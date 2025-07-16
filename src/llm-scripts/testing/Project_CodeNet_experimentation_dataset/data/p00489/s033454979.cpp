#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n,a,b,c,d,jun[101],x;
typedef pair<int,int> P;
P t[101];

bool cmp(const P& a,const P& b){
	return a.first == b.first ? a.second < b.second : a.first > b.first;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) t[i].second=i;
	for(int i=1;i<=n*(n-1)/2;i++){
		cin>>a>>b>>c>>d;
		if(c>d) t[a].first+=3;
		else if(c<d) t[b].first+=3;
		else {t[a].first++; t[b].first++;}
	}
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(i>1&&t[i].first==t[i-1].first){
			jun[t[i].second]=x;
		}
		else{
			jun[t[i].second]=i;
			x=i;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<jun[i]<<endl;	
	}
}