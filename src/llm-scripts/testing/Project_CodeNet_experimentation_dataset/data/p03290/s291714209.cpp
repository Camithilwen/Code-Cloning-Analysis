#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int d;
    ll g;
    cin >> d >> g;
    vector<int> p(d);
    vector<ll> c(d),a(d);
    rep(i,d){
        cin >> p[i] >> c[i];
    }
    rep(i,d){
        a[i]=(i+1)*100*(p[i]-1);
    }
    ll ans=100000000000000000;
    for(int bit=0;bit<(1<<d);++bit){
        ll pr=0,preans=0;
        vector<int> t;
        for(int i=0;i<d;++i){
            if(bit&(1<<i)){
                pr+=((i+1)*100*p[i]+c[i]);
                preans+=p[i];
            }else{
                t.push_back(i);
            }
        }
        int x=0;
        ll res=0;
        for(auto u:t){
            if(res<a[u]) x=u;
            res=max(res,a[u]);
        }
        if(g>pr){
            ll y=g-pr;
            if(y%(100*(x+1))!=0 && (pr+res)>=g){
                preans+=(y/(100*(x+1))+1);
            }else if(y%(100*(x+1))==0 && (pr+res)>=g){
                preans+=y/(100*(x+1));            
            }else{
                continue;
            }
        }
        ans=min(ans,preans);
    }
    cout << ans << "\n";
    return 0;
}   