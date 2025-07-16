#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int maxx=x,miny=y,xd,yd;
    rep(i,n){
        cin>>xd;
        maxx=max(maxx,xd);
    }
    rep(i,m){
        cin>>yd;
        miny=min(miny,yd);
    }
    if(maxx<miny) cout<<"No War";
    else cout<<"War";
}