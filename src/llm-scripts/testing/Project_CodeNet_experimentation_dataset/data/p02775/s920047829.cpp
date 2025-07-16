#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    string N;cin>>N;
    reverse(N.begin(),N.end());
    vector<vector<ll>> dp(1000010,vector<ll>(2/*桁上がりあるか*/,INF));
    dp[0][0]=0;

    N.push_back('0');
    for(ll i=0;i<N.size();i++){
        ll now=N[i]-'0';

        //前桁上がり判定ありの時
        ll nowb=now+1; 
        if(dp[i][1]!=INF){
            //今equal
            chmin(dp[i+1][0],dp[i][1]+nowb);
            
            //今もbigger
            chmin(dp[i+1][1],dp[i][1]+(10-nowb));
        }

        //前桁上がり判定無し
        if(dp[i][0]!=INF){
            //今桁上がり判定無し
            chmin(dp[i+1][0],dp[i][0]+now);
    
            //今桁上がり判定あり
            chmin(dp[i+1][1],dp[i][0]+(10-now));
        }
    }

    cout<<min(dp[N.size()][0],dp[N.size()][1])<<endl; 
    return 0;
}
