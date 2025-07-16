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
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
const ll MOD=998244353;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;

ll N,M,V,P;
ll A[100000];

bool C(int x){
    if(x<P) return true;
    if(A[x]+M<A[P-1]) return false;
    ll sum=0;
    sum+=M*P;
    sum+=M*(N-1-x);
    for(int i=P-1;i<x;i++){
        sum+=min(M,A[x]+M-A[i]);
    }
    return sum>=M*V;
}

int main(){
    cin>>N>>M>>V>>P;
    for(int i=0;i<N;i++) cin>>A[i];
    sort(A,A+N,greater<ll>());
    int l=0,r=N;
    while(r-l>1){
        int m=(l+r)/2;
        if(C(m)) l=m;
        else r=m;
    }
    cout<<l+1<<endl;
    return 0;
}