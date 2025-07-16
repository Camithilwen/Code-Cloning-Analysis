#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
ll dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int main(void){
    ll h,w;
    cin>>h>>w;
    string s[h];
    rep(0,i,h)cin>>s[i];
    ll ans=0;
    vector<vector<bool>>d(h,vector<bool>(w,false));
    rep(0,i,h){
        rep(0,j,w){
            if(d[i][j]==false){
                ll cw=0,cb=0;
                queue<pair<ll,ll>>q;
                d[i][j]=true;
                q.push({i,j});
                while(!q.empty()){
                    ll x=q.front().first,y=q.front().second;q.pop();
                    if(s[x][y]=='#')++cb;
                    else ++cw;
                    rep(0,k,4){
                        ll nx=x+dx[k],ny=y+dy[k];
                        if(!(nx>=0&&nx<h&&ny>=0&&ny<w))continue;
                        if(s[x][y]!=s[nx][ny]&&(!d[nx][ny])){
                            d[nx][ny]=true;
                            q.push({nx,ny});
                        }
                    }
                }
                //cout<<cb<<" "<<cw<<endl;
                ans+=cw*cb;
            }
        }
    }
    cout<<ans;
}