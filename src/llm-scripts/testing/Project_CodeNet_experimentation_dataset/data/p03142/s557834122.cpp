#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<ll,ll> P;
typedef pair<ll,ll> Pll;
//小数点以下　cout << fixed << setprecision(10) << num << endl;
//桁数はlog10(mid)でやれ　log(mid)/log(10)はWA
//long*long<0で判定するな
//開区間と閉区間
//アルファベットが何番目かは x=s[i]-'a'
//bfsはmain()内で　rep(i,h)rep(j,w)rep(i,4)でバグ
//切り上げ：(a+(b-1))/b
//32bit以上は 1ull<<j
// map 初期値0 for(auto itr=mp.begin();itr!=mp.end();++itr) itr->fi itr->se で全探索
// for(auto u:mp) u.fi u.se も可能
//n個のgcd,lcmは一つずつみて更新していく
//大きな数を扱うときは素因数分解した形で持っておく
// (l/a[i]) = l*powmod(a[i],MOD-2)%MOD;
//auto itr=lower_bound(ALL(a),key) a[itr-a.begin()]


//根は片が入ってないやつ

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> to(n); //to[a]=b a->b
    vector<vector<int>> from(n);
    vector<bool> pre(n,1);
    rep(i,n+m-1){
        int a,b; cin >> a >> b;
        a--; b--;
        to[a].pb(b);
        from[b].pb(a);
        pre[b]=0;
    }
    int res[n];
    int st;
    rep(i,n){
        if(pre[i]){
            res[i]=-1;
            st=i;
            break;
        }
    }
    queue<int> q;
    vector<bool> visit(n,0);
    visit[st]=1;
    q.push(st);
    while(!q.empty()){
        int v=q.front(); q.pop();
        for(auto u:to[v]){
            if(visit[u]) continue;
            bool ok=1; //pre(u)=v?
            for(auto w:from[u]){
                if(!visit[w] || res[w]==v) ok=0;
            }
            if(ok){
                visit[u]=1;
                q.push(u);
                res[u]=v;
            }
        }
    }
    rep(i,n){
        cout << res[i]+1 << endl;
    }
    return 0;
}

