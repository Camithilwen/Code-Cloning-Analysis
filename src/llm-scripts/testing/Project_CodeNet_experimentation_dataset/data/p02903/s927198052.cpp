#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(a) (a).begin(),(a).end()
 
using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
 
const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

int main(){
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    rep(i, h){
        rep(j, w){
            if(j < a){
                if(i < h-b)cout << 1;
                else cout << 0;
            }
            else {
                if(i < h-b)cout << 0;
                else cout << 1;
            }
        }
        cout << endl;
    }
}