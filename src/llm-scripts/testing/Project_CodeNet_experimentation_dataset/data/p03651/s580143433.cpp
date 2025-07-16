#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n, k;

int main(void){
    cin >> n >> k;
    vector<lli> a(n);
    rep(i, n) cin >> a[i];
    if(find(a.begin(), a.end(), k) != a.end()){
        cout << "POSSIBLE" << endl;
        return 0;
    }
    if(*max_element(a.begin(), a.end()) < k){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    lli g = 0;
    rep(i, n) g = __gcd(g, a[i]);
    if(k%g == 0){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
