#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define MOD ((ll)1e9+7)
ll N,S;
vector<pll> xpv[2];
ll i, j, k,ans;
bool ck(ll t,ll aa,ll bb){
    return t ? (aa <= bb) : (aa < bb);
}
int main(){
    //printf("%lld\n", MOD);
    scanf("%lld%lld", &N,&S);
    fornum(i,0,N){
        ll x, p;
        scanf("%lld%lld", &x, &p);
        xpv[S < x].push_back(mp(abs(x - S), p));
    }
    sort(xpv[0].begin(), xpv[0].end(), greater<pll>());
    sort(xpv[1].begin(), xpv[1].end(), greater<pll>());
    if(xpv[0].size()*xpv[1].size()==0){
        printf("%lld",xpv[0].size()?xpv[0][0].first:xpv[1][0].first);
        return 0;
    }

    ll n = 0, t = 0;
    ll ii[]={0,0};
    n= xpv[0][0].second+xpv[1][0].second;
    if(xpv[0][0].second<xpv[1][0].second){
        t = 0;
    }else{
        t = 1;
    }
    ii[t]++;
    ans += xpv[t][0].first + xpv[!t][0].first * 2;
    //printf("%lld,%lld\n", xpv[t][0].second, xpv[!t][0].second);
    while(true){
        while(ii[t]<xpv[t].size()&&ck(t,xpv[t][ii[t]].second,n)){
            //printf("%lld,%lld\n", xpv[t][ii[t]].second, n);
            n += xpv[t][ii[t]].second;
            ii[t]++;
        }
        //printf("%lld,%lld,%lld\n", t, ii[t],n);
        if(ii[t]==xpv[t].size())
            break;
        n += xpv[t][ii[t]].second;
        ans += xpv[t][ii[t]].first*2;
        t = !t;
        ii[t]++;
    }
    printf("%lld", ans);

    return 0;
}