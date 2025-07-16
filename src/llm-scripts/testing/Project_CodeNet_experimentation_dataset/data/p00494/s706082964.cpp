#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back

int solve(int a,int b,int c){
    if(c==0)return 0;
    if(b<=c&&b<=a)return b;
    return 0;
}

int main(){
    string s;
    cin>>s;
    int ans=0;
    static int J[2000000]={},O[2000000]={},I[2000000]={};
    if(s[0]=='J')J[0]=1;
    for(int i=1;i<s.size();i++){
//        cout<<s[i-1]<<" "<<J[i-1]<<" "<<O[i-1]<<" "<<I[i-1]<<endl;
        if(s[i]=='J'){
            if(O[i-1]!=0){
                ans=max(ans,solve(J[i-1],O[i-1],I[i-1]));
                J[i]=1;
            }
            else{
                J[i]=J[i-1]+1;
                O[i]=O[i-1];
                I[i]=I[i-1];
            }
        }else if(s[i]=='O'){
            if(J[i-1]!=0&&I[i-1]==0){
                J[i]=J[i-1];
                O[i]=O[i-1]+1;
                I[i]=I[i-1];
            }else{
                ans=max(ans,solve(J[i-1],O[i-1],I[i-1]));
            }
        }else if(s[i]=='I'){
            if(O[i-1]!=0){
                J[i]=J[i-1];
                O[i]=O[i-1];
                I[i]=I[i-1]+1;
            }
            else{
                ans=max(ans,solve(J[i-1],O[i-1],I[i-1]));
            }
        }
    }
    ans=max(ans,solve(J[s.size()-1],O[s.size()-1],I[s.size()-1]));
    cout<<ans<<endl;
}