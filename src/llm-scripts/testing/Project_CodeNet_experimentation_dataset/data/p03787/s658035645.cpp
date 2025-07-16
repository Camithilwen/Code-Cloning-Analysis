#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

vector<int>E[200000];
int id[200000];
int col[200000];
bool b[200000];

bool dfs(int v,int k,int c){
	id[v]=k;
	col[v]=c;
	bool flag=true;
	for(int u:E[v]){
		if(id[u]==-1){
			flag&=dfs(u,k,!c);
		}
		else{
			if(col[u]==col[v])flag=false;
		}
	}
	return flag;
}
vector<int>v[200000];

int main(){
	int n,m;cin>>n>>m;
	rep(i,m){
		int a,b;scanf("%d%d",&a,&b);a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	memset(id,-1,sizeof(id));
	int cnt=0;
	rep(i,n){
		if(id[i]==-1){
			b[cnt]=dfs(i,cnt,0);
			cnt++;
		}
		v[id[i]].push_back(i);
	}
	ll c1=0,c2=0,c3=0;
	rep(i,cnt){
		if(v[i].size()==1){
			c1++;
			continue;
		}
		c2++;
		if(b[i])c3++;
	}
	cout<<c1*(n-c1)*2+c1*c1+c2*c2+c3*c3<<endl;
}