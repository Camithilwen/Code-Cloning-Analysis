#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int n;
string s;

bool judge(string ans){
    bool ok=true;
    if(ans[n-1]=='S'){
        if(s[n-1]=='o' && ans[n-2]!=ans[0]) ok=false;
        if(s[n-1]=='x' && ans[n-2]==ans[0]) ok=false;
    }
    else{
        if(s[n-1]=='o' && ans[n-2]==ans[0]) ok=false;
        if(s[n-1]=='x' && ans[n-2]!=ans[0]) ok=false;
    }
    if(ans[0]=='S'){
        if(s[0]=='o' && ans[n-1]!=ans[1]) ok=false;
        if(s[0]=='x' && ans[n-1]==ans[1]) ok=false;
    }
    else{
        if(s[0]=='o' && ans[n-1]==ans[1]) ok=false;
        if(s[0]=='x' && ans[n-1]!=ans[1]) ok=false;
    }
    return ok;
}

int main(){
    cin>>n>>s;

    string ans="SS";
    for(int i=1;i<n-1;i++){
        if(ans[i]=='S'){
            if(s[i]=='o'){
                if(ans[i-1]=='S') ans+='S';
                else ans+='W';
            }
            else{
                if(ans[i-1]=='S') ans+='W';
                else ans+='S';
            }
        }
        else{
            if(s[i]=='o'){
                if(ans[i-1]=='S') ans+='W';
                else ans+='S';
            }
            else{
                if(ans[i-1]=='S') ans+='S';
                else ans+='W';
            }
        }
    }
    
    if(judge(ans)){
        cout<<ans<<endl;
        return 0;
    }

    ans="SW";
    for(int i=1;i<n-1;i++){
        if(ans[i]=='S'){
            if(s[i]=='o'){
                if(ans[i-1]=='S') ans+='S';
                else ans+='W';
            }
            else{
                if(ans[i-1]=='S') ans+='W';
                else ans+='S';
            }
        }
        else{
            if(s[i]=='o'){
                if(ans[i-1]=='S') ans+='W';
                else ans+='S';
            }
            else{
                if(ans[i-1]=='S') ans+='S';
                else ans+='W';
            }
        }
    }
    if(judge(ans)){
        cout<<ans<<endl;
        return 0;
    }

    ans="WS";
    for(int i=1;i<n-1;i++){
        if(ans[i]=='S'){
            if(s[i]=='o'){
                if(ans[i-1]=='S') ans+='S';
                else ans+='W';
            }
            else{
                if(ans[i-1]=='S') ans+='W';
                else ans+='S';
            }
        }
        else{
            if(s[i]=='o'){
                if(ans[i-1]=='S') ans+='W';
                else ans+='S';
            }
            else{
                if(ans[i-1]=='S') ans+='S';
                else ans+='W';
            }
        }
    }
    if(judge(ans)){
        cout<<ans<<endl;
        return 0;
    }
    
    ans="WW";
    for(int i=1;i<n-1;i++){
        if(ans[i]=='S'){
            if(s[i]=='o'){
                if(ans[i-1]=='S') ans+='S';
                else ans+='W';
            }
            else{
                if(ans[i-1]=='S') ans+='W';
                else ans+='S';
            }
        }
        else{
            if(s[i]=='o'){
                if(ans[i-1]=='S') ans+='W';
                else ans+='S';
            }
            else{
                if(ans[i-1]=='S') ans+='S';
                else ans+='W';
            }
        }
    }
    if(judge(ans)){
        cout<<ans<<endl;
        return 0;
    }

    cout<<-1<<endl;
}
