#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;




int main(){
    string s;
    cin>>s;
    vector<ll> Mnext(26,0);
    vector<vector<ll>> back(s.size()+1,Mnext);
    for(int i=0;i<s.size();i++){
        back[i+1]=Mnext;
        Mnext[s[i]-'a']=i+1;
    }
    for(int i=0;i<26;i++){Mnext[i]=s.size();}
    vector<vector<ll>> next(s.size()+1,Mnext);
    for(ll i=s.size()-1;i>=0;i--){
        next[i]=Mnext;
        Mnext[s[i]-'a']=i;
    }
    ll k;
    cin>>k;
    ll ans=0;
    vector<vector<vector<ll>>> dp(s.size()+1,vector<vector<ll>>(s.size()+1,vector<ll>(k+1,0)));
    for(int i=1;i<=s.size();i++){
        for(int t=1;t<=s.size();t++){
            for(int h=0;h<=k;h++){
                dp[i][t][h]=max(dp[i-1][t][h],dp[i][t-1][h]);
                if(s[i-1]==s[s.size()-t]){
                    dp[i][t][h]=max(dp[i][t][h],dp[i-1][t-1][h]+1);
                    for(int w=0;w<26;w++){
                        dp[i][t][h]=max(dp[i][t][h],dp[back[i][w]][s.size()-next[s.size()-t][w]][h]+1);
                    }
                }
                if(h!=0){
                    dp[i][t][h]=max(dp[i][t][h],dp[i-1][t-1][h-1]+1);
                }
            }
        }
    }
    for(int i=0;i<=s.size();i++){
        for(int t=0;t<=s.size();t++){
            for(int h=0;h<=k;h++){
                if(i+t<=s.size()){ans=max(ans,dp[i][t][h]*2);}
                if(i+t==s.size()+1){ans=max(ans,dp[i][t][h]*2-1);}
            }
        }
    }
    cout<<ans<<endl;
    

    return 0;
}
