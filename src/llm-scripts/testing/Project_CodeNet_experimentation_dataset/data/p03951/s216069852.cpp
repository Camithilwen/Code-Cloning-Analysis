#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,ans;
    string s,t;
    cin>>n>>s>>t;
    ans=n;
    for(int i=0;i<n;i++){
        if(s.substr(i)==t.substr(0,n-i))break;
        ans++;
    }
    cout<<ans<<endl;
}
