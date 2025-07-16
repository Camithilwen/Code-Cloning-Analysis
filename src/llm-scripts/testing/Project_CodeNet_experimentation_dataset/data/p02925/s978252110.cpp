#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
vector<ll> pw2(62,1);vector<ll> pw10(19,1);

//x vs y
//の試合の数字を返す
vector<vector<ll> > memo(1001,vector<ll>(1001,INF));
ll cnt=0;
ll game(ll x,ll y){
    if(x>y) swap(x,y);
    
    if(memo[x][y]!=INF) return memo[x][y];
    else return memo[x][y]=++cnt;
}

vector<ll> G[500050];//辺
//v:足跡
//c:cからのdfsの終了証明
vector<ll> visited(500050);
vector<ll> calculated(500050);
//d:c済みのとき、そのdfsの深さ
vector<ll> d(500050);

//最長経路を返す,閉路あれば-1
ll dfs(ll x){
    if(visited[x]){
        //dfs終わってないくせにまた訪れた = 閉路
        if(!calculated[x]) return -1;
        
        else return d[x];
    }
    
    //あしあと
    visited[x]=true;
    
    //枝先のmaxをとる
    ll ret=0;
    rep(i,sz(G[x])){
        ll tmp=dfs(G[x][i]);
        //-1は即伝搬
        if(tmp==-1) return -1;
        
        //更新作業
        chmax(ret,tmp);
    }
    
    //dfs終了!
    calculated[x]=true;
    
    return d[x]=ret+1;
}

int main(){
    //dの初期化
    rep1(i,500049) d[i]=INF;
    
    //入力
    ll N; cin>>N;
    ll ans=0;
    vector<vector<ll> > A(N+1,vector<ll>(N,0));
    rep1(i,N){
        rep1(j,N-1){
            cin>>A[i][j];
        }
    }
    
    //初日にやる試合をリストへ
    vector<ll> dfs_list;
    //iとjが初日のペアなら初日にやって良い
    //inする
    rep1(i,N-1){
        FOR(j,i+1,N+1){
            if(A[A[i][1]][1]==i) dfs_list.pb(game(i,j));
        }
    }
    
    //試合の前後を表す辺を張る
    rep1(i,N){
        //iは、A[i][j]との試合の後にしかA[i][j+1]との試合をできない
        rep1(j,N-2){
            G[game(i,A[i][j])].pb(game(i,A[i][j+1]));
        }
    }
    
    if(sz(dfs_list)==0) cout<<-1<<endl;
    else{
        rep(i,sz(dfs_list)){
            ll tmp=dfs(dfs_list[i]);
            //閉路発見
            if(tmp==-1){
                cout<<-1<<endl;
                return 0;
            }
            
            chmax(ans,tmp);
        }
        
        cout<<ans<<endl;
    }
}

