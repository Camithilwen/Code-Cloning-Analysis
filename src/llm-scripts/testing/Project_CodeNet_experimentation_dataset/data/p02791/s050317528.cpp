#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    int p[200010];
    int ans=0;
    int tmp=200010;
    rep(i, n){
        cin>>p[i];
        if(tmp>p[i]) ans++;
        tmp=min(tmp,p[i]);
    }
    cout<<ans<<endl;
}