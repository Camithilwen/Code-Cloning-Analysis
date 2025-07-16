#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int a,b; cin>>a>>b;
    string s; cin>>s;
    bool ok=true;
    rep(i,a){
        if(s[i]-'0'>=0 && s[i]-'0'<=9){

        }else{
            ok=false;
        }
    }
    if(s[a]!='-') ok=false;
    for(int i=a+1; i<a+b+1; ++i) {
        if(s[i]-'0'>=0 && s[i]-'0'<=9){

        }else{
            ok=false;
        }
    }
    cout<<(ok?"Yes":"No")<<endl;
}