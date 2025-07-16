#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    int n,m,A[301][301],B[301][301];
    cin>>n>>m;
    rep(i,n)rep(j,m) cin>>A[i][j],B[i][A[i][j]]=j+1;
    int num[301],ans=n;
    rep(i,m) num[i+1]=1;
    rep(i,m){
        int C[301]={0};
        rep(j,n){
            int a=m,b;
            rep(k,m) if(num[k+1]){
                if(a>=B[j][k+1]) a=B[j][k+1],b=k+1;
            }
            C[b]++;
        }
        int a=0,b;
        rep(j,m) if(a<=C[j+1]) a=C[j+1],b=j+1;
        ans=min(ans,a),num[b]--;
    }
    cout<<ans<<"\n";
}