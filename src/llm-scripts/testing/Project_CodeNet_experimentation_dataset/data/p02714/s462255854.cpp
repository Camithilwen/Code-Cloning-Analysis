#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <algorithm>

//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define repr1(i, n) for (int i = n; i > 0; i--)
#define FOR(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
const ll MOD = 1000000007; // 10^9+7
const ll INF = 10000000000;

int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;

    ll r=0,g=0,b=0;
    rep(i,n){
        if(s[i] == 'R') r++;
        if(s[i] == 'G') g++;
        if(s[i] == 'B') b++;
    }

    ll cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(2*j-i >= n) continue;
            if(s[i] != s[j] && s[j] != s[2*j-i] && s[2*j-i] != s[i]) cnt++;
        }
    }

    cout << r*g*b - cnt << endl;
    return 0;
}