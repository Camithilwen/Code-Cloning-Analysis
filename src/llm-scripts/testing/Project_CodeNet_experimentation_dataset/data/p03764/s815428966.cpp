#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <array>
#include <bitset>
using namespace std;

typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<n+1;i++)
int main(){
    int n,m;
    ll x1,x2,X=0,y1,y2,Y=0;
    cin>>n>>m;
    //x
    cin>>x1;
    rep(i,n-1){
        cin>>x2;
        X=(X+(x2-x1)*(i+1)*(n-i-1))%mod;
        x1=x2;
    }
    //y
    cin>>y1;
    rep(i,m-1){
        cin>>y2;
        Y=(Y+(y2-y1)*(i+1)*(m-i-1))%mod;
        y1=y2;
    }
    cout<<(X*Y)%mod<<endl;
    return 0;
}