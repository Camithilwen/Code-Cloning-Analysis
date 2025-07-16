#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define eb emplace_back
using namespace std;
string s;
ll ans=1,cnt=0,n;
const int mod=1e9+7;
int main(){
    cin>>n>>s;
    for(auto x:s){
        if(x=='W'&&(cnt&1)){
            cnt++;
        }else if(x=='B'&&!(cnt&1)){
            cnt++;
        }else{
            (ans*=cnt)%=mod;
            cnt--;
        }
    }
    for(ll i=1;i<=n;i++){
        (ans*=i)%=mod;
    }
    if(cnt){
        ans=0;
    }
    cout<<ans<<endl;
    return 0;
}