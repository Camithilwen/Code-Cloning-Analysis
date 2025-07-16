#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define imin INT_MIN
#define imax INT_MAX
int mod =1e9+7;
//~ vector<bool> cats;

//~ ll ans;
//~ ll n,m;
//~ void dfs(vector<vector<int>>& graph,int s,int consCats,int parent){
	//~ if(consCats>m) return;
	//~ if(graph[s].size()==1 && graph[s][0]==parent)
	//~ {
		//~ if(cats[s]) consCats++;
		//~ if(consCats<=m) ans++;
		//~ return;
	//~ }
	//~ if(!cats[s]) consCats=0;
	//~ else consCats++;
	//~ for(auto val:graph[s]){
		//~ if(val!=parent)
		//~ dfs(graph,val,consCats,s);
	//~ }


int main(){
	cin.tie(NULL);
    ios_base::sync_with_stdio();

	ll n;
	cin>>n;
	vector<int> a(n);
	
	rep(i,0,n-1) cin>>a[i];
	sort(a.begin(),a.end());
	ll ans=0;
	int i=0;
	while(i<n-2){
		int j=i+1;
		int outer=0;
		
		while(j<n-1){
			int local=0;
			if(a[j]!=a[i])
			rep(k,j+1,n-1){
				if(a[k]!=a[j])
					if(a[i]+a[j]>a[k])
					local++;
			}
			int tmp=a[j];
			while(j<n-1 && a[j]==tmp) { 
				outer+=local;
				j++;
			}
		}
		int tmp=a[i];
		while(i<n-2 && a[i]==tmp){
		ans+=outer;
		i++;}
	}
	cout<<ans;
	
	return 0;
}
