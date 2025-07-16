#include <iostream>
#include <functional>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <complex>
#include <random>
#include <bitset>
#include <list>
// #include <prettyprint.hpp>
using namespace std;
#define repi(i,n) for(int i=0;i<n;++i)
#define rep(i,n) for(ll i=0;i<n;++i)
#define repinvi(i,n) for(int i=n-1;i>=0;--i)
#define sll(n) scanf("%lld", &n);
#define sii(n) scanf("%d", &n);
#define slf(n) scanf("%lf", &n);
#define pll pair<ll,ll>
#define pii pair<int,int>
#define psi pair<si,si>
typedef long long ll;
typedef double lf;
typedef short int si;

void Main(){
    ll N, l;
    sll(N);
    // vector<ll> ls(N, 0);
    map<ll, ll> counter;
    rep(i, N){
        sll(l);
        counter[l] ++;
    }

     
    ll ans = 0;
    for(auto p1:counter){
        for(auto p2:counter){
            if(p1.first >= p2.first){
                continue;
            }
            for(auto p3:counter){
                if(p1.first >= p3.first){
                    continue;
                }else if(p2.first >= p3.first){
                    continue;
                }

                if(p3.first >= p1.first + p2.first){
                    continue;
                }

                ans += (p1.second * p2.second * p3.second);

            }
        }
    }

    cout << ans <<endl;
}

int main(){
    Main();
}