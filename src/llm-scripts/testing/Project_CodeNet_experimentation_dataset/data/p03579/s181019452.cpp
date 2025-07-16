#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int long long
typedef long long ll;

int color[200000];

int n,m;
vector<vector<int>> v(200000);
/*
bool dfs(int nn, int pre, int c){
    for(int x:v[nn]){
        if(x==pre) continue;
        if(color[x]==-1) color[x]=1-c;
        //if(color[x]!=c) continue;
        if(color[x]==c) return false;
        
        if(!dfs(x,nn,color[x])) return false;
    }

    return true;
}*/

bool dfs(int vv,int c){
    color[vv]=c;
    for(auto x:v[vv]){
        if(color[x]==c) return false;
        if(color[x]==0 && !dfs(x,-c)) return false;
    }
    return true;
}


signed main(){
    cin >> n >> m;
    memset(color,0,sizeof(color));
    rep(i,m){
        int aa,bb;
        cin >> aa >> bb;
        v[aa-1].push_back(bb-1);
        v[bb-1].push_back(aa-1);
    }

    //color[0]=0;
    rep(i,n){
        if(color[i]==0){
            if(!dfs(i,1)){
                cout << ((n*(n-1))/2)-m << endl;
                return 0;
            }
        }
    }


    int white=0;
    int black=0;
    rep(i,n){
        if(color[i]==1) white++;
        else black++;
    }
    //cout << white << black << endl;
    cout << white*black-m << endl;
    


    


}