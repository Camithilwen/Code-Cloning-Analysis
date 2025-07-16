#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<P,P> PP;
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=100100100100100;


int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> v(n);
    vector<ll> sum(n+1);
    ll s=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum[i+1]=sum[i]+v[i];
        s+=v[i];
    }
    ll ans=-INF;
    for(int l=0;l<=n;l++){
        for(int r=0;r<=n;r++){
            if(l>r) continue;
            ll buf=0;
            int life=k;
            vector<ll> q(0);
            for(int i=0;i<l;i++){
                buf+=v[i];
                q.push_back(v[i]);
                life--;
            }
            for(int i=r;i<n;i++){
                buf+=v[i];
                q.push_back(v[i]);
                life--;
            }
            if(life<0) continue;
            sort(q.begin(), q.end());
            int m=q.size();
            for(int i=0;i<min(life,m);i++){
                if(q[i]>=0) break;
                buf-=q[i];
            }
            ans=max(ans,buf);
        }
    }
    cout<<ans<<endl;
}