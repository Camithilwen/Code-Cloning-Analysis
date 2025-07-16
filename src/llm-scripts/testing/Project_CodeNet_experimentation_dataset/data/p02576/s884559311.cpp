#include<bits/stdc++.h>
using namespace std;
#define lli long long int
# define rep(i,n) for(int i=0;i<n;i++)
void solve(){
    lli n,x,t;
    cin>>n>>x>>t;
    lli y = (t*n)/x;
    if(y%t==0)
        cout<<y<<endl;
    else{
        y +=t;
        cout<<y - y%t<<endl;
    }   
}
int main()
{
    int t;
   // cin>>t;
    t=1;
    while(t--){
        solve();
    }
}