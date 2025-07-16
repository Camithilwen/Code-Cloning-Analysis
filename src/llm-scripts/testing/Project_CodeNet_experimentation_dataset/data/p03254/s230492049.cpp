#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main() {
    int n,x;cin >>n>>x;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
    }
    sort(all(a));
    ll sum=0;
    int ans=0;
    for (int i = 0; i < n; ++i) {
        sum+=a[i];
        if(sum<=x){
            ans++;
        }
    }
    if(sum<x){
        ans--;
    }
    cout <<ans <<endl;
}