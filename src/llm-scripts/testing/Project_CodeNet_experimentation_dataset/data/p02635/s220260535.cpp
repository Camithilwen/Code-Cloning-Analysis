#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[309][309][309],A[309],S[309][309][309];
ll mod = 998244353;
void admod(ll &x, ll y){
    x = (x +y) % mod;
}
main(){
    string s;
    ll k;
    cin >> s >> k;
    ll n = s.size();
    if(k > n) k = n;
    vector<ll> A;
    ll o = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] == '1') o++;
        else A.push_back(o), o =0;
    }
    A.push_back(o);
    ll m = A.size();
    reverse(A.begin(),A.end());

    dp[0][0][0] = 1;
    for(ll i = 0; i <= m; i++){
        for(ll s = 0; s <= k; s++)
            for(ll j = k; j >=0; j--)
                admod(S[i][s][j], S[i][s][j+1]);
        for(ll car = 0; car <= k; car ++){
            for(ll pl = 0; car + pl <= k; pl++){

                admod(dp[i][car][pl], S[i][car+pl][car]);
                if(i < m){
                    admod(S[i+1][car+pl][car] , dp[i][car][pl]);
                    for(ll j = 1; j <= A[i]; j++)
                        admod(dp[i+1][car + j][pl],  dp[i][car][pl]);
                }

            }
        }
    }
    ll ans = 0;
    for(ll i = 0; i <= k; i++)
        admod(ans, dp[m][0][i] );
    cout<<ans<<endl;

}
