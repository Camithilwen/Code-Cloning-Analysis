#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dp[3005][3005];
int subdp[3005][3005];

int main(){
    int N,T;
    cin>>N>>T;
    vector<vector<int>> v(N,vector<int>(2));
    rep(i,N) cin>>v[i][1]>>v[i][0];
    sort(v.begin(),v.end());
    rep(i,N){
        rep(j,T){
            chmax(dp[i+1][j],dp[i][j]);
            if(j+v[i][1]<T) chmax(dp[i+1][j+v[i][1]],dp[i][j]+v[i][0]);
        }
    }
    int time = T-1;
    vector<bool> use(N);
    int ans = 0;
    for(int i = N-1; i >= 0; i--){
        if(time>=v[i][1]){
            if(dp[i+1][time]==dp[i][time - v[i][1]] + v[i][0]){
                time -= v[i][1];
                use[i]=true;
                continue;
            }
        }
    }
    vector<vector<int>> nouse;
    rep(i,N){
        if(!use[i]) nouse.push_back({v[i][0],v[i][1]});
    }
    rep(i,N){
        rep(j,T){
            chmax(dp[i+1][j],dp[i][j]);
            if(j+v[i][1]<T) chmax(dp[i+1][j+v[i][1]],dp[i][j]+v[i][0]);
        }
    }
    int m = nouse.size();
    rep(i,m){
        rep(j,T){
            chmax(subdp[i+1][j],subdp[i][j]);
            if(j+nouse[i][1]<T) chmax(subdp[i+1][j+nouse[i][1]],subdp[i][j]+nouse[i][0]);
        }
    }
    vector<int> exceptmax(N);
    rep(i,N){
        if(use[i]) exceptmax[i] = dp[N][T-1]-v[i][0]+subdp[m][v[i][1]];
        else exceptmax[i] = dp[N][T-1];
    }
    rep(i,N) chmax(ans,exceptmax[i]+v[i][0]);
    cout<<ans<<endl;
}