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
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> P;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
const ll MOD=1e9+7;


int main(){
    int N,M;cin>>N>>M;
    vector<ll> A(N),S(N+1,0);
    map<int,ll> mp;
    mp[0]++;
    for(int i=0;i<N;++i) cin>>A[i];
    for(int i=0;i<N;++i){
        S[i+1]=S[i]+A[i];
        S[i+1]%=M;
        mp[S[i+1]]++;
    }
    ll ans=0;
    for(auto it:mp){
        ans+=(it.second)*(it.second-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}