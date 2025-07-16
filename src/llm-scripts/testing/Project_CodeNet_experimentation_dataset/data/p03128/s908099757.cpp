#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

string dp[100000];

string smax(string a, string b){
    if(a.size() > b.size()){
        return a;
    }else if(a.size() < b.size()){
        return b;
    }else{
        rep(i, 0, a.size()){
            if(a[i] > b[i]){
                return a;
            }else if(a[i] < b[i]){
                return b;
            }
        }
    }
    return a;
}

int main(){
    ll N, M;
    cin >> N >> M;
    VL A(M);

    ll c[10] = {0,2,5,5,4,5,6,3,7,6};
    rep(i, 0, M) cin >> A[i];
    
    rep(i, 0, 100000){
        dp[i] = "-";
    }

    dp[0] = "";
    rep(i, 0, N+1){
        if(dp[i] == "-") continue;
        for(auto a : A){
            if(dp[i+c[a]] == "-") dp[i+c[a]] = dp[i] + (char)(a + '0');
            else dp[i+c[a]] = smax(dp[i+c[a]], dp[i] + (char)(a + '0'));
        }
    }

    cout << dp[N] << endl;
    return 0;
}