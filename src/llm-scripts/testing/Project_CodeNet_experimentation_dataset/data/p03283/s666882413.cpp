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
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
typedef long long ll;
typedef pair<ll,ll> pll;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;
const ll MOD=1e9+7;
struct edge{
    int to;
    int cost;
};

int main(){
    int N,M,Q;cin>>N>>M>>Q;
    vector<vector<int> > S(N+1,vector<int>(N+1,0));
    for(int i=0;i<M;++i){
        int L,R;cin>>L>>R;
        S[L][R]++;
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<=N;++j){
            S[i+1][j]+=S[i][j];
        }
    }
    for(int j=0;j<N;++j){
        for(int i=0;i<=N;++i){
            S[i][j+1]+=S[i][j];
        }
    }
    while(Q--){
        int p,q;cin>>p>>q;
        cout<<S[q][q]-S[p-1][q]-S[q][p-1]+S[p-1][p-1]<<endl;
    }
    return 0;
}