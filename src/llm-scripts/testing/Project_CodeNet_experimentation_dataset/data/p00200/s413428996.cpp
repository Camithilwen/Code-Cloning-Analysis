#include "bits/stdc++.h"

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back


int n,m;

int C[200][200];
int T[200][200];
int d[200];


int dijk(int s,int g,int r){
    bool used[200];
    rep(i,200)used[i]=false;
    rep(i,200)d[i]=999999999;
    
    d[s]=0;
    
    while(1){
        int v=-1;
        rep(u,m){
            if( !used[u]&&(v==-1||d[u]<d[v]) )v=u;
        }
        if(v==-1)break;
        
        used[v]=true;
        
        rep(u,m){
            if(r==0)
                d[u] = min(d[u],d[v]+C[v][u]);
            else
                d[u] = min(d[u],d[v]+T[v][u]);
        }
    }
    return d[g];
}

int main(){
    while(cin>>n>>m){
        if(n==0&&m==0)break;
        
        rep(i,200)rep(j,200){
            C[i][j]=999999999;
            T[i][j]=999999999;
        }
        rep(i,n){
            int a,b,c,t;
            cin>>a>>b>>c>>t;
            a--,b--;
            C[a][b]=c;
            C[b][a]=c;
            T[a][b]=t;
            T[b][a]=t;
        }
        
        int k;
        cin>>k;
        rep(i,k){
            int s,g,r;
            cin>>s>>g>>r;
            s--,g--;
            cout<<dijk(s,g,r)<<endl;
        }
    }
}