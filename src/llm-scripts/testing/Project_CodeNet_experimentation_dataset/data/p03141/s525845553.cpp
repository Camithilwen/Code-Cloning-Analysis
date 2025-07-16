#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;

int main()
{
   ll n;cin >>n;
   V a(n),b(n);rep(i,n)cin >>a[i]>>b[i];
   vector<P> s(n);
   rep(i,n){
    ll k=a[i]+b[i];
        s[i]=make_pair(k,i);
   }
   sort(s.rbegin(),s.rend());
   ll takahasi=0,aoki=0;
   rep(i,n){
    ll key=s[i].second;
    if(i%2==0){
        takahasi+=a[key];
    }
    else {
        aoki+=b[key];
    }
   }
   cout << takahasi-aoki<< endl;
    return 0;
}
