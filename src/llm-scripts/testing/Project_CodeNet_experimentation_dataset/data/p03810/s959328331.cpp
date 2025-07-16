#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=103,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int N;

bool DFS(vector<ll> A){
    
    vector<ll> left(N+2),right(N+2);
    ll sum=0;
    for(int i=0;i<N;i++){
        sum+=A[i];
    }
    
    if((sum-N)%2){
        return 1;
    }
    
    for(int i=1;i<=N;i++){
        left[i]=gcd(left[i-1],A[i-1]);
    }
    
    for(int i=N;i>=1;i--){
        right[i]=gcd(right[i+1],A[i-1]);
    }
    
    bool res=false;
    
    for(int i=1;i<=N;i++){
        if(A[i-1]==1) continue;
        ll g=gcd(gcd(left[i-1],A[i-1]-1),right[i+1]);
        if(g==1) continue;
        
        if(((sum-1)/g-N)%2==0){
            vector<ll> to(N);
            to=A;
            for(int j=0;j<N;j++){
                if(j==i-1) to[j]--;
                to[j]/=g;
            }
            res|=!DFS(to);
        }
    }
    
    return res;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    if(DFS(A)) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    
}

