#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int xmax=x,ymin=y;
    rep(i,n){
        int x0;
        cin>>x0;
        xmax=max(xmax,x0);
    }
    rep(i,m){
        int y0;
        cin>>y0;
        ymin=min(ymin,y0);
    }
    if(xmax<ymin) cout<<"No War"<<endl;
    else cout<<"War"<<endl;
    return 0;
}