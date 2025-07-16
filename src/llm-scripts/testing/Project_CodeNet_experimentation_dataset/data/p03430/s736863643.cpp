#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vii         vector<pair<int,int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define endl '\n'
#define int long long int
using namespace std;


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    string s;cin >> s;
    int n = s.length();
    int k;cin >> k;
    vector<vi> dp(n+1, vi(n+1));
    vector<vi> prev(n+1, vi(n+1));
    for(int change = 0; change <= k; change++){
        for(int len = 1; len <= n; len++){
            for(int start =0; start <= n - len; start++){
                dp[start][len] = max(dp[start+1][len-1], dp[start][len-1]); 
                if(s[start] == s[start + len -1]){
                    dp[start][len] = max(1 + (len != 1) + dp[start+1][max(len-2,0LL)], dp[start][len]);
                }else if(change > 0){
                    dp[start][len] = max(1 + (len != 1) + prev[start+ 1][max(len-2,0LL)], dp[start][len]); 
//                cout << dp[start][len] <<  " ";
                }
            }
//            cout << endl;
        }
        swap(dp, prev);
    }
    cout << prev[0][n];
}



