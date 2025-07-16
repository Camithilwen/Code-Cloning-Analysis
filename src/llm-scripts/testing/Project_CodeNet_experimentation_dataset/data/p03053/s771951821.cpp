#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<tuple>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef unsigned long long int ull;
const int INF=1e9;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=2e5;

int h,w;
vector<vector<char> > a(1000,vector<char>(1000));
vector<vector<int> > d(1000,vector<int>(1000,INF));

int main(){
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    int ans=0;
    queue<ii> que;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){
                d[i][j]=0;
                que.push(make_pair(i,j));
            }
        }
    }
    while(!que.empty()){
        ii p=que.front();que.pop();
        int y=p.first,x=p.second;
        for(int i=0;i<4;i++){
            int ny=y+dy[i],nx=x+dx[i];
            if(ny>=0&&ny<h&&nx>=0&&nx<w&&d[ny][nx]>d[y][x]+1){
                d[ny][nx]=d[y][x]+1;
                que.push(make_pair(ny,nx));
                ans=max(ans,d[ny][nx]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}