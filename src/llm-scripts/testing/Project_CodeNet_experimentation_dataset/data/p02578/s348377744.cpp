#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    int n;
    cin >>n;
    vl a(n);
    rep(i,n) cin >> a[i];

    ll ans = 0;
    int tmp = a[0];
    rep(i,n-1){
        if(tmp > a[i+1]){
            ans += (tmp-a[i+1]);
        }else{
            tmp = a[i+1];
        }
    }

    cout << ans << endl;
    return 0;
}