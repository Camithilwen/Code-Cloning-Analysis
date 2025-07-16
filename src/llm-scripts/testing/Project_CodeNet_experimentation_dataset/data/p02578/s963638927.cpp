#include<bits/stdc++.h>
using namespace std;
using Long = long long;

int main(){
    int n;
    cin >>n;
    vector<int> v(n);
    for( auto &i : v ) cin >> i;
    int mx = 0;
    Long ans = 0LL;
    for( int i = 0 ; i < n ; ++i ){
        mx = max( mx , v[i]);
        ans += 1LL * ( mx - v[i] );
    }
    cout << ans << endl;
    return 0;
}