#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
vector<array<ll,2>> adj[mxn];
bool vis[mxn];
ll ans=0,w,check;
ll dfs(int i, ll temp, int j){
    vis[i]=true;
    ll sum=0;
    for(auto x : adj[i]){
        if(!vis[x[0]]){
            if(temp+x[0]>=check*j){
                while(x[1]>=check){
                    ans++;
                    x[1]=x[1]/2;
                }
            }
            ll k=dfs(x[0],temp+x[1],j+1);
            sum=sum+k-x[1];
            if(k>=check*j){
               while(x[1]>=check){
                    ans++;
                    x[1]=x[1]/2;
                }
            }
            sum=sum+x[1];
        }
    }
    return sum;
}
int main(){
    int n,m,q,u,v;
    cin>>n>>m>>q;
    map<int,int> a,b;
    u=v=INT_MAX;
    for(int i=1;i<=n;i++){
        int c;
        cin>>c;
        u=min(u,c);
        a[i]=c;
    }
    for(int i=1;i<=m;i++){
        int c;
        cin>>c;
        b[i]=c;
        v=min(c,v);
    }
    int  ans=INT_MAX;
    while(q--){
        int x,y,z;
        cin>>x>>y>>z;
        int  temp=a[x]+b[y]-z;
        ans=min(ans,temp);
    }
    cout<<min(v+u,ans);
}

