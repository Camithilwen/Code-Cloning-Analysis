#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD=1e9+7;

int main(void){
    int h,w;
    cin>>h>>w;
    vector<string> M(h);
    rep(i,h) cin>>M[i];
    queue<pair<int,int>> que;
    vector<vector<int>> seen(h,vector<int>(w,-1));
    rep(i,h) rep(j,w){
        if(M[i][j]=='#'){
            que.push(make_pair(i,j));
            seen[i][j]=0;
        }
    }
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    while(!que.empty()){
        int x=que.front().first;
        int y=que.front().second;
        que.pop();
        rep(dir,4){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx<0 || nx>=h || ny<0 ||ny>=w) continue;
            if(seen[nx][ny]!=-1) continue;
            seen[nx][ny]=seen[x][y]+1;
            que.push(make_pair(nx,ny));
        }
    }
    
    int ans=0;
    rep(i,h){
        rep(j,w){
            //cout<<seen[i][j]<<" ";
            ans=max(ans,seen[i][j]);
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
}