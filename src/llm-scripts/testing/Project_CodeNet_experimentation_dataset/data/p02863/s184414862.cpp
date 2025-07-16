#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    int N,T; cin>>N>>T;
    vector<pair<int,int>> AB;
    rep(i,N){
        int a,b; cin>>a>>b;
        AB.push_back({a,b});
    }
    sort(AB.begin(),AB.end());
    vector<vector<int>> dp(N+1,vector<int> (T+1,0));
    for(int i = 0; i < N; i++){
        for(int t = 0; t < T; t++){
            int a = AB.at(i).first;
            int b = AB.at(i).second;
            if(a+t>T)dp.at(i+1).at(T) = max(dp.at(i+1).at(T),dp.at(i).at(t)+b);
            if(a>t)dp.at(i+1).at(t) = dp.at(i).at(t);
            else{
                dp.at(i+1).at(t) = max(dp.at(i).at(t),dp.at(i).at(t-a)+b);
            }
        }
    }
    int res = 0;
    rep(i,N+1)res = max({res,dp.at(i).at(T-1),dp.at(i).at(T)});
    cout<<res<<endl;
}
