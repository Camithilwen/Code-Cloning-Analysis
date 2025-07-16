#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    for(int T = 0; T < t ; T++){
        ll n, x;
       cin >> n >> x;
       ll a[n], ans = 0;
       for(int i = 0; i < n; i++)
            cin >> a[i];
       if(a[0] > x){
           ans += a[0] - x;
           a[0] = x;
       }
       for(int i = 1; i < n; i++){
           if(a[i] + a[i - 1] > x){
                ans += a[i] + a[i -1] - x;
               a[i] = x - a[i - 1];
           }
       }
       std::cout << ans  << std::endl;
    }
    return 0;
}