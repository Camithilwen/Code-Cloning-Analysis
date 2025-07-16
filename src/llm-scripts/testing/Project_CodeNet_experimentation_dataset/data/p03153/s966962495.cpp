#include<cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX_N 262144
#define INF 1000000000000000
typedef long long ll;
using namespace std;

int used[MAX_N];
ll n,d,a[MAX_N],ans=0,two[20];
pair<ll,ll> p[MAX_N],t[2*MAX_N][2];
vector<pair<ll,ll> > g[MAX_N];
void init(){
    for(ll i=0;i<2*MAX_N;i++){
        t[i][0]=t[i][1]=make_pair(INF,i);
    }
    two[0]=1;
    for(int i=1;i<20;i++){
        two[i]=two[i-1]*2;
    }
}
void change(ll i){
    ll y=p[i].second+MAX_N;
    t[y][0].first=d*(y-MAX_N)+p[i].first;
    t[y][1].first=d*(n-1-y+MAX_N)+p[i].first;
    y/=2;
    while(y>0){
        t[y][0]=min(t[2*y][0],t[2*y+1][0]);
        t[y][1]=min(t[2*y][1],t[2*y+1][1]);
        y/=2;
    }
}
pair<ll,ll> smq(ll l,ll r,int y){
    ll cnt=1,x=l;
    if(l==r){
        return t[l][y];
    }
    while(x>0){
        if(x/2*two[cnt]==l&&(x/2+1LL)*two[cnt]-(1LL)==r){
            return t[x/2][y];
        }
        else if(x/2*two[cnt]<l||(x/2+1LL)*two[cnt]-(1LL)>r){
            return min(t[x][y],smq((x+1LL)*two[cnt-1],r,y));
        }
        x/=2;
        cnt++;
    }
    return t[x][y];
}
int main(){
    pair<ll,ll> x;
    priority_queue<pair<ll,ll> ,vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    scanf("%lld %lld",&n,&d);
    for(ll i=0;i<n;i++){
        scanf("%lld",&a[i]);
        p[i]=make_pair(a[i],i);
    }
    init();
    sort(p,p+n);
    change(0);
    for(ll i=1;i<n;i++){
        x=smq(p[i].second+MAX_N,n-1+MAX_N,0);
        if(x.first<INF){
            g[p[i].second].push_back(make_pair(x.first-d*p[i].second+p[i].first,x.second-MAX_N));
            g[x.second-MAX_N].push_back(make_pair(x.first-d*p[i].second+p[i].first,p[i].second));
        }
        x=smq(MAX_N,p[i].second+MAX_N,1);
        if(x.first<INF){
            g[p[i].second].push_back(make_pair(x.first-d*(n-1-p[i].second)+p[i].first,x.second-MAX_N));
            g[x.second-MAX_N].push_back(make_pair(x.first-d*(n-1-p[i].second)+p[i].first,p[i].second));
        }
        change(i);
    }
    used[p[n-1].second]=1;
    for(int i=0;i<g[p[n-1].second].size();i++){
        q.push(g[p[n-1].second][i]);
    }
    while(!q.empty()){
        x=q.top();
        q.pop();
        if(used[x.second]==0){
            ans+=x.first;
            for(int i=0;i<g[x.second].size();i++){
                q.push(g[x.second][i]);
            }
            used[x.second]=1;
        }
    }
    printf("%lld\n",ans);
}