/*
      author  : nishi5451
      created : 14.08.2020 21:24:46
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

const int INF = 2020202020;

int main(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    int l = x, r = y;
    rep(i,n){
        int a;
        cin >> a;
        l = max(l,a);
    }
    rep(i,m){
        int a;
        cin >> a;
        r = min(r,a);
    }
    if(r-l >= 1) cout << "No War" << endl;
    else cout << "War" << endl;

    return 0;
}