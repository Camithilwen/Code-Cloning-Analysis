#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;



int main() {
    int n,m,x,y; cin >> n >> m >> x >> y;
    int mx = -101, ym = 101;
    vector<int> vec;
    for(int i = 0;i < n;i++){
        int a; cin >> a;
        mx = max(mx,a);
        if(x < a && a <= y) vec.push_back(a);
    }
    for(int i = 0;i < m;i++){
        int b; cin >> b;
        ym = min(ym,b);
        if(x < b && b <= y) vec.push_back(b);
    }
    string ans = "War";
    for(int i = 0;i < vec.size();i++){
        if(mx < vec[i] && vec[i] <= ym){
            ans = "No War";
            break;
        }
    }
    cout << ans;
}
