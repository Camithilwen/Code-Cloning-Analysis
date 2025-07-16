#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF=1001001001;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};

int main(){
    int h,w;
    cin>>h>>w;
    int ans=0;
    vector<string>s(h);
    rep(i,h)cin>>s[i];
    rep(i,h)rep(j,w)if(s[i][j]=='.')ans++;
    vector<vector<int>>dist(h,vector<int>(w,INF));
    queue<P>q;
    q.push(P(0,0));
    dist[0][0]=1;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        rep(dir,4){
            int vy=y+dy[dir];
            int vx=x+dx[dir];
            if(vy<0||vy>=h||vx<0||vx>=w)continue;
            if(s[vy][vx]=='#'||dist[vy][vx]!=INF)continue;
            dist[vy][vx]=dist[y][x]+1;
            q.push(P(vy,vx));
        }
    }
    ans-=dist[h-1][w-1];
    if(dist[h-1][w-1]!=INF)cout<<ans<<endl;
    else cout<<-1<<endl;
}