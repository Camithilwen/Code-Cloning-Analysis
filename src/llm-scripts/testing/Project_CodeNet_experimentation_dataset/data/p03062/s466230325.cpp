#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const ll INF = 1000100100100100100;

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

int main()
{
    int n; cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];

    ll dp[n][2];
    rep(i,n) rep(j,2) dp[i][j] = 0;
    dp[0][1] = -INF;

    rep(i,n){
        if(i == n-1){
            dp[i+1][0] = max(dp[i][0]+a[i], dp[i][1]-a[i]);
            dp[i+1][1] = -INF;
        }
        else{
            dp[i+1][0] = max(dp[i][0]+a[i], dp[i][1]-a[i]);
            dp[i+1][1] = max(dp[i][0]-a[i], dp[i][1]+a[i]);
        }
    }

    cout << dp[n][0] << endl;
}