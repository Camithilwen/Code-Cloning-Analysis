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
    int n; cin>>n;
    string s; cin>>s;
    vector<int> p(n);
    if(s[0]=='E') p[0]=-1;
    else p[0]=1;
    rep(i,n-1){
        if(s[i+1]=='E') p[i+1]=-1;
        else p[i+1]=1;
        p[i+1]+=p[i];
    }
    auto an=min_element(btoe(p));
    int ba=an-p.begin();
    int ans=0;
    rep(i,n){
        if(i<ba){
            if(s[i]=='W') ans++;
        }
        else if(i>ba){
            if(s[i]=='E') ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}