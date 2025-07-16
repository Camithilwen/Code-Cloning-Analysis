#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    ll y;
    cin >> n >> y;
    int a,b,c;
    a=-1;
    b=-1;
    c=-1;
    int cnt=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            if((1000*i+5000*j+10000*(n-i-j))==y){
            a=n-i-j;
            b=j;
            c=i;
            }
        }
    }

    cout << a << " " << b << " " << c << endl;
    return 0;
}