#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 1;

    map<int,int> c;

    int z = 3;

    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            ans *= z;
            ans %=mod;
            c[0+1]++;
            z--;
        } else {
            ans *= c[a[i]];
            c[a[i]]--;
            ans %= mod;
            c[a[i]+1]++;
        }
    }

    cout << ans << endl;

    return 0;
}