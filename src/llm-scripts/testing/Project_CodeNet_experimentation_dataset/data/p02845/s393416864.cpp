#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int dp[3][100010];

int main(){

    rep(i,3){
        rep(j,100010){
            dp[i][j] = 0;
        }
    }

    int n;
    int tmp ;
    ll ans = 1;
    ll mod = 1e9+7;
    
    cin >> n;
    vector<int> vec(n);
    rep(j,n){
        cin >> tmp;
        vec[j] = tmp;
        rep(i,3){
            dp[i][j+1] = dp[i][j];
        }
        rep(i,3){
            if(dp[i][j+1] == tmp) {
                dp[i][j+1] = tmp+1;
                break;
            }
        }
    }
    
    rep(j,n){
        ll cnt = 0;
        rep(i, 3){
            if(dp[i][j] == vec[j]){
                cnt++;
            }
        }
        ans = (ans*cnt) % mod;
    }

    cout << ans << endl;
    return 0;
}