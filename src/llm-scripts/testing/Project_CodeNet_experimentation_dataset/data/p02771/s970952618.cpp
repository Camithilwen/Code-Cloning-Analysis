#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int a,b,c;cin>>a>>b>>c;
    bool flag=false;
    if(a==b){
        if(a!=c){
            flag=true;
        }
    }else if(a==c){
        flag=true;
    }else{
        if(b==c){
            flag=true;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}