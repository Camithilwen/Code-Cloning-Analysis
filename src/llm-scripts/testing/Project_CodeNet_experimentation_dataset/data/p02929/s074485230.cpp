typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
    ll n;
    string s;
    std::cin >> n>>s;
    
    ll rc = 0;
    
    string c = "L";
    for (int i = 1; i < n*2; i++) {
        if(s[i]!=s[i-1]){
            if(c[i-1]=='R'){
                c += 'R';
                rc++;
            }else{
                c += 'L';    
            }
        }else{
            if(c[i-1]=='R'){
                c += 'L';
            }else{
                c += 'R';
                rc++;
            }
        }
    }
    if(s[0]=='W'){
        std::cout << 0 << std::endl;
        return 0;
    }

    if(rc!=n){
        std::cout << 0 << std::endl;
        return 0;
    }
    if(c[2*n-1]=='L'){
        std::cout << 0 << std::endl;
        return 0;
    }
    rc = 0;
    ll ans = 1;

    for (int i = 2*n-1; i >=0; i--) {
        if(c[i]=='R'){
            rc++;
        }else{
            if(rc==0){
                std::cout << 0 << std::endl;
                return 0;
            }
            ans *= rc;
            rc--;
            ans %= MOD;
        }
    }

    for (int i = 0; i < n; i++) {
        ans *= i+1;
        ans %= MOD;
    }
    std::cout << ans << std::endl;
}