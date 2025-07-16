#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll n, x, cnt = 0;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i=0; i<n; i++){
        if ((i<n-1 && a[i]<=x) || (i==n-1 && a[i]==x)){
            x -= a[i];
            cnt++;
        } else{
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}