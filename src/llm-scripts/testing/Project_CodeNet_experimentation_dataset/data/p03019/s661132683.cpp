#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
ll MOD=1000000007;
int inf=1000000000;
ll INF=10000000000000000;
int main(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> b(n),l(n),u(n);
    vector<pair<ll,ll>> a(n);
    ll uu=0;
    rep(i,n){
        cin >> b.at(i) >> l.at(i) >> u.at(i);
        a.at(i).first=u.at(i)*(x-b.at(i))+l.at(i)*b.at(i);
        a.at(i).second=i;
        uu+=l.at(i)*b.at(i);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    ll sum=0,v;
    rep(i,n){
        sum+=a.at(i).first;
        if (sum>uu) {sum-=a.at(i).first;v=i;break;}
        if (sum==uu) {cout << (i+1)*x << endl;return 0;}
    }
    ll ans=INF;
    rep(i,n){
        ll y=sum;
        int p=a.at(i).second;
        if (i<v) y=sum-a.at(i).first+a.at(v).first;
        ll t=uu-y+(u.at(p)-l.at(p))*b.at(p);
        ll o=t/u.at(p);
        if (t%u.at(p)!=0) o++;
        ans=min(ans,v*x+o);
        t=uu-y;
        o=t/l.at(p);
        if (t%l.at(p)!=0) o++;
        ans=min(ans,v*x+o);
    }
    cout << ans << endl;
}