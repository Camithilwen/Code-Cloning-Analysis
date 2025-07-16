#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main(){
    int a,n,ans=1e9,b;
    string s,t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        b=0;
        while(a%2==0){
            b++;
            a/=2;
        }
        ans=min(b,ans);
    }
    cout<<ans<<"\n";
    return(0);
}