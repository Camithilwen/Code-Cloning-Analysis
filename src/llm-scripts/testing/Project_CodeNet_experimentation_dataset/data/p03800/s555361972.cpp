//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ld pie=3.1415926535;
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,cnt=0; cin>>n;
    string s; cin>>s;
    vector<string> c={"SS","SW","WS","WW"};
    for(auto st:c){
        string ans=s;
        ans[0]=st[0]; ans[1]=st[1];
        for(int i=2;i<n;i++){
            if(ans[i-2]=='S' && ans[i-1]=='S' && s[i-1]=='o')
            ans[i]='S';
            if(ans[i-2]=='S' && ans[i-1]=='S' && s[i-1]=='x')
            ans[i]='W';
            if(ans[i-2]=='S' && ans[i-1]=='W' && s[i-1]=='o')
            ans[i]='W';
            if(ans[i-2]=='S' && ans[i-1]=='W' && s[i-1]=='x')
            ans[i]='S';
            if(ans[i-2]=='W' && ans[i-1]=='S' && s[i-1]=='o')
            ans[i]='W';
            if(ans[i-2]=='W' && ans[i-1]=='S' && s[i-1]=='x')
            ans[i]='S';
            if(ans[i-2]=='W' && ans[i-1]=='W' && s[i-1]=='o')
            ans[i]='S';
            if(ans[i-2]=='W' && ans[i-1]=='W' && s[i-1]=='x')
            ans[i]='W';
        }
        if(ans[n-1]=='S'){
            if((ans[n-2]==ans[0] && s[n-1]=='o') ||
               (ans[n-2]!=ans[0] && s[n-1]=='x')){
               if(ans[0]=='S'){
                   if((ans[n-1]==ans[1] && s[0]=='o') ||
               (ans[n-1]!=ans[1] && s[0]=='x')){
                   cout<<ans<<endl;
                   break;
               }
               }
               else{
                   if((ans[n-1]==ans[1] && s[0]=='x') ||
               (ans[n-1]!=ans[1] && s[0]=='o')){
                   cout<<ans<<endl;
                   break;
               }
               }
               }
        }
        else{
            if((ans[n-2]==ans[0] && s[n-1]=='x') ||
               (ans[n-2]!=ans[0] && s[n-1]=='o')){
               if(ans[0]=='S'){
                   if((ans[n-1]==ans[1] && s[0]=='o') ||
               (ans[n-1]!=ans[1] && s[0]=='x')){
                   cout<<ans<<endl;
                   break;
               }
               }
               else{
                   if((ans[n-1]==ans[1] && s[0]=='x') ||
               (ans[n-1]!=ans[1] && s[0]=='o')){
                   cout<<ans<<endl;
                   break;
               }
               }
               }
        }
        cnt++;
        if(cnt==4) cout<<-1<<endl;
    }
}