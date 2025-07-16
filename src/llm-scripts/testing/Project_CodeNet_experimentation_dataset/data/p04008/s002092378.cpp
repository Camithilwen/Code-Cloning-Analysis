#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;


void array_show(int *a,int n){
	for(int i=0;i<n;i++)printf("%d%c",a[i],(i!=n-1?' ':'\n'));
}
void array_show(LL *a,int n){
	for(int i=0;i<n;i++)printf("%lld%c",a[i],(i!=n-1?' ':'\n'));
}

int t[100005];
int bef[100005];
bool used[100005];
vector<int> path_rev[100005];
vector<int> v1;
vector<P> v2;

void check(int a,int m){
	v1.push_back(a);
	if(v1.size()>=m){
		bef[a]=v1[v1.size()-m];
	}
	v2.push_back(make_pair(v1.size()-1,a));
	for(int i=0;i<path_rev[a].size();i++){
		check(path_rev[a][i],m);
	}
	v1.pop_back();
}

void set_used(int a){
	if(used[a])return;
	used[a]=true;
	for(int i=0;i<path_rev[a].size();i++){
		set_used(path_rev[a][i]);
	}
}

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	int s=0;
	cin>>n>>m;
	memset(t,-1,sizeof(t));
	for(i=0;i<n;i++){
		cin>>t[i];
		t[i]--;
		if(i==0){
			if(t[i]!=0)s++;
			continue;
		}
		path_rev[t[i]].push_back(i);
	}
	check(0,m);
	sort(v2.rbegin(),v2.rend());
	for(i=0;i<n;i++){
		if(v2[i].first<=m)break;
		j=v2[i].second;
		if(used[j])continue;
		s++;
		set_used(bef[j]);
	}
	cout<<s<<endl;
	return 0;
}
