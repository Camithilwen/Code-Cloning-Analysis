#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N;
    cin >> N;
    ll cur = 0;
    ll now = -2;
    vector<ll> v;
    if(N==0)v.push_back(0);
    while(N != 0){
        if(N % now == 0){
            v.push_back(0);
        }else{
            v.push_back(1);
            N--;
        }
        N /= -2;
    }
    reverse(v.begin(),v.end());
    rep(i,v.size()){
        cout << v[i];
    }
    cout << endl;
}