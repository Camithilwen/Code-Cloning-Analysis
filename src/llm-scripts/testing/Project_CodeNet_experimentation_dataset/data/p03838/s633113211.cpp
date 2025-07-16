#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int x,y;
    cin>>x>>y;
    int ans=2e9;
    if(y>=x)ans=min(ans,y-x);
    x=-x;
    if(y>=x)ans=min(ans,y-x+1);
    x=-x,y=-y;
    if(y>=x)ans=min(ans,y-x+1);
    x=-x;
    if(y>=x)ans=min(ans,y-x+2);
    cout<<ans<<endl;
}