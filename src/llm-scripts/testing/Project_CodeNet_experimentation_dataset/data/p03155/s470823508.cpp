// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで
 
#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;
 
int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
 
    ll a,b,c,d,m,n,maxi=0,f=0,mini=INF,sum=0,h,w;
    string str;
    cin>>n>>h>>w;
    a=n-h+1;
    b=n-w+1;
    cout<<a*b<<endl;

 
    return 0;
}