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
    ll n,y;
    cin>>n>>y;
    ll noguchi=0,higuchi=0;
    rep(i,n+1){
        rep(j,n+1-i){
            if((y-(1000*i+5000*j))%10000==0&&(y-(1000*i+5000*j))/10000==n-i-j){
                printf("%d %d %d",n-i-j,j,i);
                return 0;
            }
        }
    }
    printf("-1 -1 -1");
}