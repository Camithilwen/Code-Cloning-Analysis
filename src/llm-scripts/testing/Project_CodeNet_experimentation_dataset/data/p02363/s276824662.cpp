#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;

int d[101][101];
int inf=INT_MAX;
int v;
int warshall_floyd(){
    rep(k,v)rep(i,v)rep(j,v){
        if(d[i][k]==inf||d[k][j]==inf)continue;
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
}
int main(){
    int e,r,s,t,ds;
    cin>>v>>e;
    rep(i,v)rep(j,v) d[i][j]=inf;
    rep(i,v) d[i][i]=0;
    rep(i,e){
        cin>>s>>t>>ds;
        d[s][t]=ds;
    }
    warshall_floyd();
    rep(i,v){
        if(d[i][i]<0){
            cout<<"NEGATIVE CYCLE"<<endl;
            break;
        }
        else if(i==v-1){
            rep(j,v){
                rep(k,v){
                    if(d[j][k]<inf) cout<<d[j][k];
                    else cout<<"INF";
                    if(k==v-1) cout<<endl;
                    else cout<<" ";
                }
            }
        }
    }
    return 0;
}