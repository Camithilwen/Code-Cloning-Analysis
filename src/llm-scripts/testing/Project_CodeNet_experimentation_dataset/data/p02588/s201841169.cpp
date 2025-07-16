#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n){
        double b;
        cin >> b;
        b *= 1000000000;
        a[i] = (ll)(b+0.0005);
    }
    map<Pi,int> cnt;
    rep(i,n){
        ll now = a[i];
        int cnt2 = 0;
        while(now%2 == 0){
            cnt2++;
            now /= 2;
        }
        now = a[i];
        int cnt3 = 0;
        while(now%5 == 0){
            cnt3++;
            now /= 5;
        }
        cnt[Pi(cnt2,cnt3)]++;
    }
    ll ans = 0;
    ll ans2 = 0;
    for(auto p1: cnt){
        for(auto p2: cnt){
            if(p1.first.first+p2.first.first >= 18 && p1.first.second+p2.first.second >= 18){
                if(p1 == p2){
                    ans2 += (ll)p1.second*(p1.second-1)/2;
                }
                else ans += (ll)p1.second*p2.second;
            }
        }
    }
    ans = ans/2+ans2;
    cout << ans << endl;
}

