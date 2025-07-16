#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

ll pow[19];

ll dfs(int k, int i, ll dif, ll dif_org){
    // if(k == 4) cout << dif << endl;
    if(i < k-i+1) return dif == 0 ? 1:0;
    if(i == k-i+1){
        if(dif == 0){
            if(k != i){
                return 10;
            }else{
                return 9;
            }
        }else{
            return 0;
        }
    }
    ll d = pow[i-1]-pow[k-i];
    ll r = dif%d;
    ll m = dif/d;
    ll sum = 0;
    if(r == 0){
        if(abs(m) < 10) {
            if(k != i){
                sum += (10-abs(m))*dfs(k, i-1, r, dif_org);
            }else{
                sum += (10-abs(m)-1)*dfs(k, i-1, r, dif_org);
            }
        }
    }else{
        if(abs(m) < 10) {
            if(k != i){
                sum += (10-abs(m))*dfs(k, i-1, r, dif_org);
            }else{
                sum += (10-abs(m)-1)*dfs(k, i-1, r, dif_org);
            }
        }
        if(dif > 0){
            if(abs(m)+1 < 10) {
                if(k != i){
                    sum += (10-abs(m)-1)*dfs(k, i-1, r-d, dif_org);
                }else{
                    sum += (10-abs(m)-2)*dfs(k, i-1, r-d, dif_org);
                }
            }
        }else if(dif < 0){
            if(abs(m)+1 < 10) {
                if(k != i){
                    sum += (10-abs(m)-1)*dfs(k, i-1, r+d, dif_org);
                }else{
                    sum += (10-abs(m)-2)*dfs(k, i-1, r+d, dif_org);
                }
            }
        }
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    pow[0] = 1;
    for(int i = 1; i < 19; i++) pow[i] = pow[i-1]*10; 
    ll D;
    cin >> D;
    ll ans = 0;
    for(int i = 1; i <= 19; i++){
        ans += dfs(i, i, D, D);
        // cout << i << ' ' << ans << endl;
    }
    cout << ans << endl;
}