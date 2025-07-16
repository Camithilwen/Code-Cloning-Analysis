#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n,m;
    cin>>n>>m;
    string ans{};
    rep(i,n) ans.push_back('a');
    bool err=false;
    rep(i,m){
        int s;
        char c;
        cin>>s>>c;
        s--;
        if(ans[s]=='a'||ans[s]==c){
            ans[s]=c;
        }else{
            err=true;
        }
    }
    if(ans[0]=='0'&&n>1) err=true;
    rep(i,n){
        if(ans[i]=='a'){
            if(i==0&&n>1) ans[i]='1';
            else ans[i]='0';
        }
    }
    if(!err) cout<<ans<<endl;
    else cout<<-1<<endl;
}