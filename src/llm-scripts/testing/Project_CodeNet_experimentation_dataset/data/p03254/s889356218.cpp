/**
*    author:  yuya1234
*    created: 25.06.2020 13:29:29
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n,x,tmp;
    vector<ll> v;

    cin>>n>>x;

    REP(i,n)
    {
        cin>>tmp;
        v.push_back(tmp);
    }

    SORT(v);

    ll cnt=0;

    REP(i,n)
    {
        if((x>=v[i] && i!=n-1) || x==v[i]) 
        {
            x-=v[i];
            cnt++;
        }
    }

    cout<<cnt<<endl;

    return 0;
}