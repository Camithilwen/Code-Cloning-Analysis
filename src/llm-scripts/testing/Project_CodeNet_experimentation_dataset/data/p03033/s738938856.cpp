#include <bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define vii vector<ii>
#define all(X) (X).begin(),(X).end()
#define xx first
#define yy second
#define FOR(i,l,r) for( int i = l-(l>r); i != r-(l>r); i += 1-2*(l>r) )

int main() {
    int n,q; cin>>n>>q;
    vector<pair<int,ii>> v;
    FOR(i,0,n) {
        int s,t,x; cin>>s>>t>>x;
        v.pb({x,{s-x,t-1-x}});
    }
    sort(all(v));
    set<ii> s;
    FOR(i,0,q) {
        int u; cin>>u;
        s.insert({u,i});
    }
    int ans[q];
    memset(ans,-1,sizeof(ans));
    for( auto e : v ) {
        if( !s.size() ) break;
        auto i1 = s.lb({e.yy.xx,-1});
        auto i2 = s.ub({e.yy.yy,n+5});
        auto i = i1;
        vii temp;
        while( i != i2 ) {
            temp.pb(*i);
            i++;
        } 
        for( auto ee : temp ) {
            s.erase(ee);
            ans[ee.yy] = e.xx;
        }
    }
    for( auto e : ans ) cout<<e<<"\n";
    return 0;
}