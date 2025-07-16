#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int H,W,sy,sx,gy,gx;
int N;

int C[100][100];
bool vis[100][100];

signed main(){
    while(cin>>W>>H,W||H){
        cin>>sx>>sy>>gx>>gy;
        cin>>N;
        sy--;sx--;gy--;gx--;
        memset(C,0,sizeof(C));
        rep(i,N){
            int c,d,x,y;
            cin>>c>>d>>x>>y;
            x--;y--;
            for(int dy=0;dy<2;dy++){
                for(int dx=0;dx<4;dx++){
                    int ny,nx;
                    if(!d)ny=y+dy,nx=x+dx;
                    else ny=y+dx,nx=x+dy;
                    C[ny][nx]=c;
                }
            }
        }
        if(!C[sy][sx]){
            cout<<"NG"<<endl;
            continue;
        }

        memset(vis,0,sizeof(vis));
        queue<pint>que;
        que.push(pint(sy,sx));
        vis[sy][sx]=true;
        while(que.size()){
            int y,x;
            tie(y,x)=que.front();
            que.pop();
            rep(i,4){
                int ny=y+dy[i],nx=x+dx[i];
                if(ny<0||ny>=H||nx<0||nx>=W||C[y][x]!=C[ny][nx]||vis[ny][nx])continue;
                vis[ny][nx]=true;
                que.push(pint(ny,nx));
            }
        }
        if(vis[gy][gx])cout<<"OK"<<endl;
        else cout<<"NG"<<endl;
    }
    return 0;
}