#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int n,m,a[300][300],ans=999;
bool ok[301];

int main(){
    cin>>n>>m;
    rep(i,n)rep(j,m)cin>>a[i][j];
    rep(k,m){
        int x[301]={};
        rep(i,n){
            int j=0;
            while(ok[a[i][j]])j++;
            x[a[i][j]]++;
        }
        int X=1;
        for(int i=1;i<=m;i++){
            if(x[X]<x[i])X=i;
        }
        ans=min(x[X],ans);
        ok[X]=1;
    }
    cout<<ans<<endl;
}