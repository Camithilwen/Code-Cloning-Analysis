#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmax(T &a,const T b){if(a < b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,const T b){if(a > b){a=b; return true;} return false;}

const int MAX_N=1005;
const int MAX_V=MAX_N*(MAX_N-1)/2;
vii G(MAX_V);
int id[MAX_N][MAX_N];
bool vis[MAX_V];
bool fin[MAX_V];
int dp[MAX_V];

int dfs(int v){
    if(vis[v]){
        if(!fin[v]) return -1;
        else return dp[v];
    }
    vis[v]=true;
    dp[v]=1;
    for(auto &nv : G[v]){
        int res=dfs(nv);
        if(res == -1) return -1;
        dp[v]=max(dp[v], res+1);
    }
    fin[v]=true;
    return dp[v];
}

int main(){
    int n; cin >> n;
    vii a(n, vi(n-1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int num=0;
    for(int i=0; i<n-1; i++) for(int j=i+1; j<n; j++) id[i][j]=num++;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(i > a[i][j]) a[i][j]=id[a[i][j]][i];
            else a[i][j]=id[i][a[i][j]];
        }
        for(int j=0; j<n-2; j++){
            G[a[i][j]].push_back(a[i][j+1]);
        }
    }
    int ans=0;
    for(int i=0; i<num; i++){
        int res=dfs(i);
        if(res == -1){
            ans=-1;
            break;
        }
        chmax(ans, res);
    }
    cout << ans << endl;
    return 0;
}