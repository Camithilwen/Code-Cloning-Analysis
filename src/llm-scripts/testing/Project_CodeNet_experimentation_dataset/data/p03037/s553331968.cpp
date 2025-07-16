#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int n, m;
    cin >> n >> m;
    int mx = 0, mn = 1e9;
    for(int i = 0, l, r; i < m; i++){
        cin >> l >> r;
        mx = max(mx, l);
        mn = min(mn, r);
    }
    cout << max(0, mn - mx + 1);
    return 0;
}
