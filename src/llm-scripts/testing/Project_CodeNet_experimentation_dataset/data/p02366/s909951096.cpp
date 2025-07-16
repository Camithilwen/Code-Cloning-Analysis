#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second

using namespace std;
const int MAX_N = 1e4+10;
const int INF = 1e9+10;
typedef long long ll;
vector <int> vec[MAX_N];
bool ans[MAX_N];
int dp[MAX_N],depth[MAX_N];
void dfs(int v,int cnt,int p){
	depth[v]=cnt+1;
	dp[v]=depth[v];
	int nd=0;
	for(int u:vec[v]){
		if(u==p)
            continue;
		if(dp[u])
			dp[v]=min(dp[v],depth[u]);
		else{
			dfs(u,cnt+1,v);
			dp[v]=min(dp[v],dp[u]);
			if(dp[u]>=depth[v])
                ans[v]=true;
            nd++;
		}
	}
    if(p==-1&&nd<2)
        ans[v]=false;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(0,0,-1);
    for(int i=0;i<n;i++)
        if(ans[i])
            cout<<i<<endl;
}