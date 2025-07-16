#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
ll dp[301][301][301] = {},dp2[301][301] = {},dp3[301][301] = {};
vector<int> v;
int main(){
    int i,j,k,l,r;
    string s; cin >> s >> k;
    s.push_back('0');
    int n = s.size();
    for(i=0;i<n;i++){
        if(s[i]=='0'){
            int cnt = 0;
            if(i==0) v.push_back(0);
            for(j=i - 1;j>=0;j--){
                if(j!=0 && s[j]=='1'){
                    cnt++;
                }else{
                    v.push_back(cnt);
                    break;
                }
            }
        }
    }
    int m = v.size(),sum = 300;
    dp[m][0][0] = 1;
    for(i=m - 1;i>=0;i--){
        for(l=0;l<=sum;l++){
            dp2[sum][l] = dp[i + 1][sum][l];
            for(j=sum - 1;j>=0;j--){
                dp2[j][l] = dp2[j + 1][l];
                (dp2[j][l] += dp[i + 1][j][l]);
            }
        }
        for(j=0;j<=sum;j++){
            for(l=0;l<=sum;l++){
                (dp[i][j][l] += dp2[j][l]) %= mod;
                for(r=1;r<=min({j,l,v[i]});r++){
                    (dp[i][j][l] += dp[i + 1][j - r][l - r]) %= mod;
                }
            }
        }
    }
    ll ans = 0;
    for(i=0;i<=min(300,k);i++){
        (ans += dp[0][0][i]) %= mod;
    }
    cout << ans << endl;
}