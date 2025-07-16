#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<int> p(n), q(m);
    rep(i,n) cin>>p[i];
    rep(i,m) cin>>q[i];
    p.push_back(x); q.push_back(y);
    sort(etob(p)); sort(btoe(q));
    int a=p[0], b=q[0];
    if(a<b) cout<<"No War"<<endl;
    else cout<<"War"<<endl;
}