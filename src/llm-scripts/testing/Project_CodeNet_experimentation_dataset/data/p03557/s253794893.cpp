#include <algorithm>
#include <iostream> //標準入出力
#include <fstream>  //ファイルでの入出力
#include <vector>
#include <set>
#include <functional>
#include <string>
#include <utility> //pair
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define MAX 1000000
#define pair(a) pair<a,a>

ll binary_search(vector<ll>& s,ll key){
    auto isOK = [&](ll index){
        if(s[index] > key) return true;
        else return false;
    };

    ll ng=-1,ok=s.size();
    while(abs(ok-ng) > 1){
        ll mid = (ok+ng)/2;
        if(isOK(mid)) ok = mid;
        else ng = mid;
    };

    return ok;
}
void _main(){
    ll n; cin >> n;
    vector<ll> a(n),b(n),c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(ALL(a));
    sort(ALL(b));
    sort(ALL(c));
    vector<ll> atob(n),btoc(n);
    ll out = 0;
    rep(i,n)  atob[i] = binary_search(b,a[i]);
    rep(i,n)  btoc[i] = binary_search(c,b[i]);
    rep(i,n){
        for (ll j = atob[i]; j < n; j++)
        {
            out += (n-btoc[j]);
        }
    }
        
    cout << out << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    