#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    rep(i,k){
        vector<int>sum(n);
        rep(j,n){
            int l=max(0,j-a[j]);
            int r=min(n,j+a[j]+1);
            sum[l]++;
            if(r!=n)sum[r]--;
        }
        rep(j,n-1)sum[j+1]+=sum[j];
        bool same=true;
        rep(j,n){
            if(a[j]!=sum[j])same=false;
            a[j]=sum[j];
        }
        if(same)break;
    }
    rep(i,n)cout<<a[i]<<" ";
}