#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    int n, m;
    cin >> n >> m;
    if(n > m)
        swap(n, m);
    int k;
    cin >> k;
    int ans = 0;
    while(k > 0){
        k -= m;
        ans++;
    }
    cout << ans;
}
