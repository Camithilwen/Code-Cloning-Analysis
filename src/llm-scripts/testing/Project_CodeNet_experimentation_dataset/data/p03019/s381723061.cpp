#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define INF 1e15
ll N, X, b[101010];
ll l[101010], u[101010];
vector<pll> mxv;
ll mk[101010];
ll i, j, k,aa,bb,dd,bs,ans;
int main(){
    scanf("%lld%lld", &N,&X);
    bs = 0;
    fornum(i,0,N){
        scanf("%lld%lld%lld", &b[i], &l[i], &u[i]);
        bs += l[i] * b[i];
        mxv.push_back({u[i] * (X - b[i]) + l[i] * b[i], i});
    }
    sort(mxv.begin(), mxv.end(), greater<pll>());
    //printf("%lld\n", bs);
    if(bs==0){
        printf("0");
        return 0;
    }
    while(bb<N&&aa<bs){
        aa += mxv[bb].first;
        ll a = mxv[bb].second;
        mk[a] = 1;
        dd += X;
        //printf("%lld %lld\n", mxv[i].second, bs);
        bb++;
    }
    bb--;
    ans = INF;
    fornum(i,0,bb){
        ll cc = bs-(aa - mxv[i].first);
        ll ii = mxv[i].second;
        ll a = dd-X;
        if(cc<=b[ii]*l[ii]){
            a += (cc - 1) / l[ii] + 1;
        }else{
            a += (cc - b[ii] * l[ii] - 1) / u[ii] + 1 + b[ii];
        }
        if(a<ans){
            ans = a;
        }
        //printf("%llda\n", ans);
    }
    fornum(i,bb,N){
        ll cc = bs-(aa - mxv[bb].first);
        ll ii = mxv[i].second;
        ll a = dd - X;
        if(cc<=b[ii]*l[ii]){
            a += (cc - 1) / l[ii] + 1;
        }else{
            a += (cc - b[ii] * l[ii] - 1) / u[ii] + 1 + b[ii];
        }
        if(a<ans){
            ans = a;
        }
        //printf("%lld\n", ans);
    }
    printf("%lld", ans);
    return 0;
}