#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const double PI = acos(-1);
vector<P> edge[100005];
vl seen(100005,INFL);
void dfs(int n,ll c,int m){
    for(auto x:edge[n]){
        if(x.first==m)continue;
        seen[x.first]=min(seen[x.first],c+x.second);
        dfs(x.first,seen[x.first],n);
    }
}
int main(){
	int n;cin>>n;
    rep(i,n-1){
        int a,b;cin>>a>>b;
        a--;b--;
        int c;cin>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    int q,k;cin>>q>>k;
    k--;
    dfs(k,0,-1);
    rep(i,q){
        int a,b;
        cin>>a>>b;
        a--;b--;
        cout<<seen[a]+seen[b]<<endl;
    }
}