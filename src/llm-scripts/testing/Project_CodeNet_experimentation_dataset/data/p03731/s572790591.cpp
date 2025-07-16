#include <bits/stdc++.h>
#define N 1005
#define INF 0x3f3f3f3f 
#define mod 1000000007
using namespace std;
typedef long long ll;
ll ans;
 
int main(){
    ll n, t;
    cin >> n >> t;
    ll arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    ans = n*t;
    for(int i=1; i<n; i++){
        if(t-(arr[i]-arr[i-1]) > 0) ans-=t-(arr[i]-arr[i-1]);
    }
    cout << ans;
    return 0;
}
